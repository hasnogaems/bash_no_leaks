#!/bin/bash

SUCCESS=0
FAIL=0
ALL=0
DIFF=""


tests=(
"OPTIONS test/test_1.txt"
"OPTIONS test/test_1.txt test/test_2.txt"
"OPTIONS test/test_1.txt test/test_2.txt test/test_3.txt"
)
flags=(
    "b"
    "e"
    "n"
    "s"
    "t"
    "v"
)
proverka=(
"-b test/testwwd_1.txt"
"-b test/test_1.txt test/test_4.txt"
"-e test/test_1.txt"
"-e test/test_1.txt test/test_4.txt"
"-n test/test_2.txt"
"-n test/test_2.txt test/test_4.txt"
"-s test/test_3.txt"
"-s test/test_3.txt test/test_4.txt"
"-v test/test_5.txt"
"-- test/test_5.txt"
"test/test_4.txt"
"-n -b test/test_1.txt"
"-s -n -e test/test_4.txt"
"-b -e -n -s -t -v test/test_3.txt"
"-benstv test/test_3.txt"
)

test() {
    peremen=$(echo "$@" | sed "s/OPTIONS/$var/")   
    ./s21_cat $peremen > ./s21_cat.log
    cat $peremen > cat.log
    DIFF=$(diff -s ./s21_cat.log cat.log)
    let "ALL++"
    if [ "$DIFF" == "Files ./s21_cat.log and cat.log are identical" ]
    then
        let "SUCCESS++"
    else
        let "FAIL++"
        
    fi
    echo "Fail:$FAIL Success:$SUCCESS All:$ALL Request:cat $peremen"
    rm -f ./s21_cat.log cat.log
}  

printf "\n"
echo "TEST"
printf "\n"


for i in "${proverka[@]}"
do
    test "$i"
done

for k1 in "${flags[@]}"
do
    for i in "${tests[@]}"
    do
        var="-$k1"
        test "$i"
    done
done
 
for k1 in "${flags[@]}"
do
    for k2 in "${flags[@]}"
    do
        if [ $k1 != $k2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$k1 -$k2"
                test "$i"
            done
        fi
    done
done

for k1 in "${flags[@]}"
do
    for k2 in "${flags[@]}"
    do
        for k3 in "${flags[@]}"
        do
            if [ $k1 != $k2 ] && [ $k2 != $k3 ] && [ $k1 != $k3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$k1 -$k2 -$k3"
                    test "$i"
                done
            fi
        done
    done
done

for k1 in "${flags[@]}"
do
    for k2 in "${flags[@]}"
    do
        for k3 in "${flags[@]}"
        do
            for k4 in "${flags[@]}"
            do
                if [ $k1 != $k2 ] && [ $k2 != $k3 ] \
                && [ $k1 != $k3 ] && [ $k1 != $k4 ] \
                && [ $k2 != $k4 ] && [ $k3 != $k4 ]
                then
                    for i in "${tests[@]}"
                    do
                        var="-$k1 -$k2 -$k3 -$k4"
                        test "$i"
                    done
                fi
            done
        done
    done
done 

for k1 in "${flags[@]}"
do
    for k2 in "${flags[@]}"
    do
        for k3 in "${flags[@]}"
        do
            if [ $k1 != $k2 ] && [ $k2 != $k3 ] && [ $k1 != $k3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$k1$k2$k3"
                    test "$i"
                done
            fi
        done
    done
done
printf "\n"
echo "RESULT: FAILED: $FAIL SUCCESS: $SUCCESS ALL: $ALL"
printf "\n"
