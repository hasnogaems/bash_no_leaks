#!/bin/bash
COUNTER=0
SUCCESS=0
FAIL=0

if [ $# -eq 0 ]; then
for i in e11
do
#diff -s <(cat -$i debug_n.txt) <(./s21_cat  debug_n.txt) 
d="$(diff -s <(grep -$i test_e.txt) <(./s21_grep -$i test_e.txt))"
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
for flag1 in e11
do
    for flag2 in v e11 c 
    do
        if [ $flag1 != $flag2 ]
        then
        combo2="-$flag1$flag2"
        dcombo2="$(diff -s <(grep -$flag1 -$flag2 test_e.txt) <(./s21_grep $combo2 test_e.txt))"
        if [ "$dcombo2" == "Files /dev/fd/63 and /dev/fd/62 are identical" ]
then
((SUCCESS++))
echo -e "$combo2 sucess!"
else
((FAIL++))
echo -e "$combo2 bugged!"   
fi 
        fi
    done
done  
echo -e "\e[1m\e[32m$SUCCESS \e[93msuccesses/\e[91m$FAIL \e[97mfails"




elif [ $# -gt 0 ]; then
diff -s <( $1 debug_n.txt) <(./s21_cat $1  debug_n.txt)
fi

