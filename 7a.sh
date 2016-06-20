#!/bin/sh
echo $*
y=$#
temp=$*
i=1
rev=' '
while [ $i -le $y ]
do
shift `expr $y - $i`
rev=$rev" "$1
i=`expr $i + 1`
set $temp
done
echo $rev
