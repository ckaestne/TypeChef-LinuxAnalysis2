#!/bin/bash
#!/bin/bash -vxe

echo WORKDIR: $1
echo COMMIT: $2
echo ARCH: $3
echo FILE: $4

if [ ! -f run.sh ]; then
  sbt mkrun
fi

. run.sh edu.cmu.typechef.linux.AnalysisFrontend "$1" "$2" "$3" "$4"


