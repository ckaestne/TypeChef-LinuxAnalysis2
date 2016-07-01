package de.fosd.typechef.linux

import java.io._
import java.util.regex.Pattern

object MakeIncludeAnalysis {
  def analyze(linuxDir: File, outputFile: Option[File], rulesFile: Option[File]) {

    val outputStream = outputFile.map(new FileOutputStream(_)).getOrElse(System.out)
    val output = new OutputStreamWriter(outputStream)
    assert(linuxDir.exists(), s"$linuxDir does not exist")


    /**
      * split along whitespace, but keep strings together
      */
    def splitParameters(p: String): List[String] = {
      val matcher = Pattern.compile("([^\\s']*)\"([^\"]*)\"|([^\\s\"]*)'([^']*)'|[^\\s\"']+").matcher(p)
      var r: List[String] = Nil
      while (matcher.find()) {
        r ::= matcher.group()
      }
      r.reverse
    }

    /**
      * finds all parameters and corresponding conditions
      */
    def analyzeMakefile(makefile: File): Map[File, List[(String, String)]] = {
      val in = io.Source.fromFile(makefile)
      val lines = in.getLines().
        map(s => if (s contains "#") s.substring(0, s.indexOf("#")) else s).
        foldRight(List[String]())(
          (s, result) => if (result.isEmpty) s :: result else if (s endsWith "\\") (s.dropRight(1) + " " + result.head) :: result.tail else s :: result
        )



      val makeFileDir = makefile.getParentFile
      val directoryFlags = lines.filter(_ startsWith "ccflags-").flatMap(s => {
        val parts = s.split("\\s[+:]?=\\s")
        assert(parts.length == 2)
        val condition = getCondition(parts(0).trim)
        val extraparams = splitParameters(parts(1))
        extraparams.map(p => (condition, p))
      })
      val fileFlags: Map[File, List[(String, String)]] = lines.
        filter(_ startsWith "CFLAGS_").filterNot(s => (s startsWith "CFLAGS_REMOVE_") || (s startsWith "CFLAGS_MODULE") || (s startsWith "CFLAGS_KERNEL")).
        map(s => {
          val parts = s.split("\\s[+:]?=\\s")
          assert(parts.length >= 1)
          val filename = parts(0).trim.drop(7).dropRight(2)
          val extraparams = if (parts.size < 2) List() else splitParameters(parts(1))
          (new File(makeFileDir, filename) -> extraparams.map(p => ("", p)))
        }).toMap

      fileFlags + (makeFileDir -> directoryFlags)
    }

    def findMakefile(dir: File): Map[File, List[(String, String)]] = {
      val files = for (file <- dir.listFiles();
                       if file.isFile && file.getName == "Makefile") yield
        analyzeMakefile(file)
      val dirs = dir.listFiles().filter(_.isDirectory).flatMap(findMakefile)
      (files.fold(Map())(mergeMaps) ++ dirs).toMap
    }

    def mergeMaps[A, B](a: Map[A, List[B]], b: Map[A, List[B]]): Map[A, List[B]] =
      (for (key <- (a.keys ++ b.keys)) yield (key -> (a.getOrElse(key, Nil) ++ b.getOrElse(key, Nil)))).toMap


    def getCondition(ccflagsStr: String): String = {
      if (ccflagsStr == "ccflags-y") ""
      else if (ccflagsStr.matches("ccflags-\\$\\(\\w+\\)")) ccflagsStr.drop(10).dropRight(1)
      else "!UNSUPPORTED<" + ccflagsStr + ">"
    }

    def getRelativePath(f: File): String =
      f.getAbsolutePath.replace(linuxDir.getAbsolutePath, "").replace("\\", "/").dropWhile(Set('\\', '/') contains _)

    def processFlag(flag: String, file: File): Option[String] = {
      if (flag.trim.isEmpty || (flag startsWith "-O")) None
      else if (flag startsWith "-I") {
        lazy val srcDir = if (file.isDirectory) file else file.getParentFile
        val x = flag.drop(2).replace("$(src)", getRelativePath(srcDir)).replace("$(srctree)/", "").replace("$(TOPDIR)", "")
        Some("-I $srcPath/" + x)
      } else if ((flag startsWith "-D") && !(flag contains "$("))
        Some(flag)
      else if ((flag startsWith "-U") && !(flag contains "$(") && !(flag contains "\""))
        Some(flag)
      else {
        System.err.println("flag not supported: " + flag)
        None
      }
    }

    val extraFlags: Map[String, List[String]] =
      (for ((file, flags) <- findMakefile(linuxDir).toList;
            (cond, flag) <- flags;
            pflag <- processFlag(flag, file))
        yield (getRelativePath(file), pflag)).groupBy(_._1).mapValues(_.map(_._2))


    for ((path, flags) <- extraFlags.toList.sortBy(_._1) if flags.nonEmpty)
      output.write(s"$path: "+flags.mkString(" ")+"\n")

    output.close()


  }
}