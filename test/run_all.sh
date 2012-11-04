#!/bin/sh
TESTDIR=$(dirname $0)
status=0

for i in $TESTDIR/*.in; do
  o=${i%.in}.out
  echo -n $(tput bold)
  printf "%-$[$(tput cols)/2-3]s   %s\n" $o "./prog1 < $i"
  echo -n $(tput sgr0)
  ./prog1 < $i > $o.run
  sdiff -w$(tput cols) $o $o.run || status=1
done

exit $status
