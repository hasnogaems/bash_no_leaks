#!/bin/bash
diff -s <(cat $1 debug_n.txt) <(./s21_cat $1 debug_n.txt) 
d="$(diff -s <(cat $1 debug_n.txt) <(./s21_cat $1 debug_n.txt))"
if [ "$d" == "Files /dev/fd/63 and /dev/fd/62 are identical" ]
then
echo -e "\e[1m\e[35m$1 \e[32msucess!"
else
echo "$1 bugged!"   
fi 
