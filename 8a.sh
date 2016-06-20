#!/bin/sh
echo "Enter file 1"
read f1
echo "Enter file 2"
read f2
ls -l $f1 >t1
x=`cut -c 2-10 t1`
ls -l $f2 >t2
y=`cut -c 2-10 t2`
if [ $x = $y ]
then
echo "COngrats dudes the file permissions are same dont worry have fun "
echo $x
else 
echo "Too bad to say the file permissions are different.sorry try again next time ps(chmod)"
echo $x $f1
echo $y $f2
fi


