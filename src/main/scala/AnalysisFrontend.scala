package edu.cmu.typechef.linux

import java.io.{File, FileWriter}

import edu.cmu.typechef.linux.Preparation._

import scala.sys.process._


object AnalysisFrontend extends App {

  if (args.size != 4) {
    throw new RuntimeException("Incorrect parameters provided, expecting <working directory> <commit id> <architecture> <file>")
  }

  val currentDir = new File(".").getAbsolutePath

  val workingDirectory = new File(args(0))
  if (!workingDirectory.exists()) workingDirectory.mkdirs()

  val commitid = args(1)

  val architecture = args(2)

  val file = args(3)


  val dir = checkoutLinuxRevision(workingDirectory, commitid, architecture)
  val _genDir = new File(dir, "gen")
  val _linuxDir = new File(dir, "linux")
  val genDir = _genDir.getAbsolutePath
  val linuxDir = _linuxDir.getAbsolutePath
  assert(_genDir.exists(), s"$genDir does not exist")
  assert(_linuxDir.exists(), s"$linuxDir does not exist")
  val dataDir = new File(currentDir, "data").getAbsolutePath

  Process(s"make allyesconfig $file.i", _linuxDir).!


  println("running TypeChef")

  createPCFile(file)

  val system = "linux-redhat"
  var typechefFlags = Seq[String](
    "--systemRoot=data/systems/redhat",
    "--postIncludes=usr/lib/gcc/x86_64-redhat-linux/4.4.4/include",
    "--predefMacros=data/host/headerboth.h",
    "--bdd",
    "-x CONFIG_",
    "--xtc",
    s"--smallFeatureModelFExpr=${dataDir}/approx.fm",
    s"--featureModelDimacs=$genDir/$architecture.dimacs ",
    //    s"--include=$genDir/$architecture.completed.h",
    s"--include=$genDir/$architecture.nonbool.h",
    s"--include=$dataDir/partialConf.h",
    "--writePI",
    s"--openFeat $genDir/$architecture.features",
    //  "--writePI --lexdebug --adjustLines --printIncludes --serializeAST "+
    "--recordTiming", "--errorXML", "--interface")

  val includeDirs: Seq[String] =
    List(s"$linuxDir/include",
      s"$linuxDir/arch/$architecture/include",
      s"$linuxDir/arch/$architecture/include/generated",
      s"$linuxDir/arch/$architecture/include/uapi",
      s"$linuxDir/arch/$architecture/include/generated/uapi",
      s"$linuxDir/include/uapi").filter(new File(_).exists())


  typechefFlags =
    typechefFlags ++ includeDirs.map("-I " + _) ++
      List[String](
        "-D __KERNEL__ ",
        "-DCONFIG_AS_CFI=1 ",
        "-DCONFIG_AS_CFI_SIGNAL_FRAME=1 ",
        "-DKBUILD_BASENAME=\"base\"",
        "-DKBUILD_MODNAME=\"base\"",
        s"--include=$dataDir/kconfig.h", s"--include=$dataDir/bounds.h", s"--include=$dataDir/asm-offsets.h") ++
      extraParameters(file)

  val command = Config.TYPECHEF + typechefFlags.mkString(" ", " ", " ") + linuxDir + "/" + file + ".c"
  println(command)

  command.!


  def extraParameters(file: String): Seq[String] =
    io.Source.fromFile(new File(_genDir, "kbuildparam.sh")).getLines().filter(file startsWith _.split(":")(0)).map(_.split(": ")(1)).map(_.replace("$srcPath", linuxDir)).toSeq

  def createPCFile(file: String): Unit = {
    val pclines = io.Source.fromFile(new File(_genDir, architecture + ".pc")).getLines().find(_.startsWith(file + ": "))
    if (pclines.isDefined) {
      val condition = pclines.get.drop(file.length + 2)
      if (condition != "True") {
        val pcFile = new FileWriter(new File(_linuxDir, file + ".pc"))
        pcFile.write(condition)
        pcFile.close
      }
    }
  }

}
