#!/bin/sh
set -x
for i in $*
do
echo "echo $i 1>$2"
echo "cat>$i << 'end of $i'"
cat $i
echo "end of $i"
done
