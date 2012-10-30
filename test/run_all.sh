#!/bin/sh
TESTDIR=$(dirname $0)

for i in $TESTDIR/*.in; do
  o=${i%.in}.out
  echo -n $(tput bold)
  printf "%-37s   %s\n" $o "./quash < $i"
  echo -n $(tput sgr0)
  ./quash < $i | sdiff -w80 $o -
done
