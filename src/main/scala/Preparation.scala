package edu.cmu.typechef.linux

import java.io.File

import de.fosd.typechef.linux.{CleanFileList, MakeIncludeAnalysis}

import scala.sys.process._


object Preparation {


  /**
    * returns the directory containing the checked out code
    */
  def checkoutLinuxRevision(workingDirectory: File, commitid: String, architecture: String): File = {
    val dir = new File(new File(workingDirectory, commitid), architecture)
    val lockFile = new File(dir, ".lock")


    //no need to do anything if the directory exists and is not locked
    if (dir.exists() && !lockFile.exists())
      return dir

    // if it exists and locked, do nothing but wait until lock is released
    if (dir.exists() && lockFile.exists()) {
      println(s"working directory $dir locked, waiting for other process to finish preparation")
      while (lockFile.exists())
        Thread.sleep(1000)
      return dir
    }

    // if directory does not exists, start preparation
    println(s"preparing Linux analysis for $commitid, $architecture")

    dir.mkdirs()
    lockFile.createNewFile()
    try {


      val linuxCheckoutDir = new File(dir, "linux")
      linuxCheckoutDir.mkdir()
      checkoutSource(workingDirectory, commitid, linuxCheckoutDir)


      val genDir = new File(dir, "gen")
      genDir.mkdir()

      Process("make allnoconfig ARCH=" + architecture, linuxCheckoutDir)

      Process("make prepare ARCH=" + architecture, linuxCheckoutDir)

      runKConfigReader(linuxCheckoutDir, genDir, architecture)

      runKbuildParameter(linuxCheckoutDir, genDir, architecture)

      runKBuildMiner(linuxCheckoutDir, genDir, architecture)

      dir
    } catch {
      case e: Throwable =>


        dir.deleteOnExit()

        throw e

    } finally {
      lockFile.delete()
    }
  }

  def checkoutSource(workingDirectory: File, commitid: String, targetDir: File): Unit = {
    val linuxRepoCloneDir = new File(workingDirectory, "linux")
    if (linuxRepoCloneDir.exists()) {
      println("updating git repository from remote " + Config.LINUXGIT)
      Process("git fetch " + Config.LINUXGIT, linuxRepoCloneDir).!
    } else {
      println("cloning git repository from remote " + Config.LINUXGIT)
      Process(s"git clone -n ${Config.LINUXGIT} linux", workingDirectory).!
    }

    println(s"checking out source code (commit $commitid) from Git repository")
    Process(s"git --work-tree=${targetDir.getAbsolutePath} checkout $commitid -- .", linuxRepoCloneDir).!
    assert(targetDir.exists(), "checkout failed")
  }


  /**
    * returns dimacs file
    */
  def runKConfigReader(linuxDir: File, genDir: File, architecture: String): File = {
    println("extracting kconfig model")
    //first building dumpconf
    Process("make allnoconfig", linuxDir).!
    Process("make scripts/kconfig/zconf.tab.o", linuxDir).!
    val dumpconfFile = new File(genDir, "dumpconf")
    s"gcc ${Config.KCONFIGREADER_DUMPCONFC} ${linuxDir.getAbsolutePath}/scripts/kconfig/zconf.tab.o -I ${linuxDir.getAbsolutePath}/scripts/kconfig/ -Wall -o ${dumpconfFile.getAbsolutePath}".!
    assert(dumpconfFile.exists(), "could not build dumpconf file for kconfigreader")

    val kconfigReaderPath = new File(Config.KCONFIGREADER).getAbsolutePath
    Process(s"$kconfigReaderPath de.fosd.typechef.kconfig.KConfigReader --writeDimacs --writeNonBoolean --dumpconf ${dumpconfFile.getAbsolutePath} arch/$architecture/Kconfig ${genDir.getAbsolutePath}/$architecture", linuxDir).!


    val dimacsFile = new File(genDir, s"$architecture.dimacs")
    assert(dimacsFile.exists, "kconfig extraction failed")
    dimacsFile
  }

  def runKBuildMiner(linuxCheckoutDir: File, genDir: File, architecture: String) = {
    println("analyzing kbuild conditions")

    val kbmPath = new File(Config.KBUILDMINER)
    val outFile = new File(genDir, architecture + ".pcr")
    val outPath = outFile.getAbsolutePath

    s"cp ${linuxCheckoutDir.getAbsolutePath}/arch/$architecture/Makefile ${linuxCheckoutDir.getAbsolutePath}/tmpMake".!
    s"""${kbmPath.getAbsolutePath} -ea gsd.buildanalysis.linux.KBuildMinerMain --codebase ${linuxCheckoutDir.getAbsolutePath} --topFolders tmpMake,block,crypto,drivers,firmware,fs,init,ipc,kernel,lib,mm,net,security,sound --pcOutput $outPath""".!

    assert(outFile.exists(), "kbuild mining failed")

    CleanFileList.perform(outFile, Some(new File(genDir, architecture + ".pc")), Some(new File(genDir, architecture+".features"))) /*,"--featureModel",new File(genDir, architecture+".dimacs").getAbsolutePath --openFeatureList $thisdir/pcs/$arch.open */
  }


  def runKbuildParameter(linuxCheckoutDir: File, genDir: File, architecture: String) = {
    println("analyzing kbuild parameters")
    val kbuildParamFile = new File(genDir, "kbuildparam.sh")
    MakeIncludeAnalysis.analyze(linuxCheckoutDir, Some(kbuildParamFile), None)

    assert(kbuildParamFile.exists(), "kbuild param extraction failed")

  }


}
