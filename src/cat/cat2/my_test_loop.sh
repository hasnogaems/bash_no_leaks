#!/bin/bash
COUNTER=0
SUCCESS=0
FAIL=0

if [ $# -eq 0 ]; then
for i in b e n s t v T E
do
#diff -s <(cat -$i debug_n.txt) <(./s21_cat  debug_n.txt) 
d="$(diff -s <(cat -$i debug_n.txt) <(./s21_cat -$i debug_n.txt))"
((COUNTER++))
if [ "$d" == "Files /dev/fd/63 and /dev/fd/62 are identical" ]
then
((SUCCESS++))
echo -e "\e[1m\e[35m-$i \e[32msucess!"
else
((FAIL++))
echo "-$i bugged!"   
fi 





done
# 2 flags
for flag1 in b e n s t v T E
do
    for flag2 in b e n s t v T E
    do
        if [ $flag1 != $flag2 ]
        then
        combo2="-$flag1$flag2"
        dcombo2="$(diff -s <(cat $combo2 test.txt) <(./s21_cat $combo2 test.txt))"
        if [ "$dcombo2" == "Files /dev/fd/63 and /dev/fd/62 are identical" ]
then
((SUCCESS++))
echo -e "\e[1m\e[35m$combo2 \e[32msucess!"
else
((FAIL++))
echo -e "\e[1m\e[97m$combo2 \e[91mbugged!\e[0m"   
fi 
        fi
    done
done  
echo -e "\e[1m\e[32m$SUCCESS \e[93msuccesses/\e[91m$FAIL \e[97mfails"




elif [ $# -gt 0 ]; then
diff -s <(cat $1 debug_n.txt) <(./s21_cat $1  debug_n.txt)
fi

