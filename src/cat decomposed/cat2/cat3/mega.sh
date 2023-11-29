#!/bin/bash

# Test case naming:
#CE1
#C - cat
#E - flag / EGNU - flag (GNU version)
#1 - number test case

echo "


first
second




	 seven

" > sample.txt

COUNTER_SUCCESS=0
COUNTER_FAIL=0
GNU_CHECK=0
DIF_RES=""
TC_NAME=""
FLAGS=""
FILE=""
TEST_CASE=""

function clear_vars() {
  FLAGS=""
  FILE=""
}

function run_utils() {
  $TEST_CASE > orig_$TC_NAME.log
  ./s21_$TEST_CASE > s21_$TC_NAME.log
}

function compare_results() {
  DIF_RES="$(diff -s orig_$TC_NAME.log s21_$TC_NAME.log)"

  if [ "$DIF_RES" == "Files orig_$TC_NAME.log and s21_$TC_NAME.log are identical" ]
    then
      echo -e "Test:$TC_NAME: \033[32m✅  Passed\033[0m"
      (( COUNTER_SUCCESS++ ))

      echo "" >> main_cat_report.log
      echo "┌──────────────────────────────────────────────────────────────────" >> main_cat_report.log
      echo "│ Test:$TC_NAME:	✅  Passed" >> main_cat_report.log
      echo "└──────────────────────────────────────────────────────────────────" >> main_cat_report.log
      echo "orig: $TEST_CASE" >> main_cat_report.log
      if [ $GNU_CHECK == 1 ] ; then
        echo orig_$TC_NAME.log >> main_cat_report.log
      else
        $TEST_CASE >> main_cat_report.log
      fi
      echo "-------------------------------------------------------------------" >> main_cat_report.log
      echo "s21_: ./s21_$TEST_CASE" >> main_cat_report.log
      ./s21_$TEST_CASE >> main_cat_report.log
      echo "-------------------------------------------------------------------" >> main_cat_report.log
    else
      echo -e "Test:$TC_NAME: \033[31m❌  Failed\033[0m"
      (( COUNTER_FAIL++ ))

      echo "" >> main_cat_report.log
      echo "┌──────────────────────────────────────────────────────────────────" >> main_cat_report.log
      echo "│ Test:$TC_NAME:	❌  Failed" >> main_cat_report.log
      echo "└──────────────────────────────────────────────────────────────────" >> main_cat_report.log
      echo "orig: $TEST_CASE" >> main_cat_report.log
      if [ $GNU_CHECK == 1 ] ; then
        echo orig_$TC_NAME.log >> main_cat_report.log
      else
        $TEST_CASE >> main_cat_report.log
      fi
      echo "-------------------------------------------------------------------" >> main_cat_report.log
      echo "s21_: ./s21_$TEST_CASE" >> main_cat_report.log
      ./s21_$TEST_CASE >> main_cat_report.log
      echo "-------------------------------------------------------------------" >> main_cat_report.log
      echo "diff -s orig_$TC_NAME.log s21_$TC_NAME.log" >> main_cat_report.log
      echo "$DIF_RES" >> main_cat_report.log
      echo "-------------------------------------------------------------------" >> main_cat_report.log
  fi
}

function run_test_case() {
  run_utils
  compare_results
}

touch main_cat_report.log
clear

echo "-------------------------------------------------------------------" >> main_cat_report.log
echo "---------------REPORT-OF-FUNCTIONAL-TEST-S21_CAT-------------------" >> main_cat_report.log
echo "-------------------------------------------------------------------" >> main_cat_report.log

echo "-------------------------------------------------------------------"
echo -e "--------------------\033[33mFUNCTIONAL-TEST-S21_CAT\033[0m------------------------"
echo "-------------------------------------------------------------------"
echo -e "----------------------\033[33mBUILDING-THE-PROJECT\033[0m-------------------------"

make

echo "-------------------------------------------------------------------"

#-------------------------------------------------------------------
clear_vars
TC_NAME="CB1"
FLAGS="-b"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CE1"
FLAGS="-e"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CN1"
FLAGS="-n"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CS1"
FLAGS="-s"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CT1"
FLAGS="-t"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CV1"
FLAGS="-v"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CNB1"
FLAGS="-nb"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CNE1"
FLAGS="-ne"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CSNE1"
FLAGS="-sne"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------
clear_vars
TC_NAME="CBENSTV1"
FLAGS="-benstv"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"
run_test_case
#-------------------------------------------------------------------

GNU_CHECK=1

#-------------------------------------------------------------------
clear_vars
TC_NAME="CBGNU1"
FLAGS="--number-nonblank"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"

./s21_$TEST_CASE > s21_$TC_NAME.log
cp ../../data-samples/gnu-samples/sample$FLAGS.txt orig_$TC_NAME.log

compare_results
#-------------------------------------------------------------------
clear_vars
TC_NAME="CEGNU1"
FLAGS="-E"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"

./s21_$TEST_CASE > s21_$TC_NAME.log
cp ../../data-samples/gnu-samples/sample$FLAGS.txt orig_$TC_NAME.log

compare_results
#-------------------------------------------------------------------
clear_vars
TC_NAME="CNGNU1"
FLAGS="--number"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"

./s21_$TEST_CASE > s21_$TC_NAME.log
cp ../../data-samples/gnu-samples/sample$FLAGS.txt orig_$TC_NAME.log

compare_results
#-------------------------------------------------------------------
clear_vars
TC_NAME="CSGNU1"
FLAGS="--squeeze-blank"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"

./s21_$TEST_CASE > s21_$TC_NAME.log
cp ../../data-samples/gnu-samples/sample$FLAGS.txt orig_$TC_NAME.log

compare_results
#-------------------------------------------------------------------
clear_vars
TC_NAME="CTGNU1"
FLAGS="-T"
FILE="sample.txt"
TEST_CASE="cat $FLAGS $FILE"

./s21_$TEST_CASE > s21_$TC_NAME.log
cp ../../data-samples/gnu-samples/sample$FLAGS.txt orig_$TC_NAME.log

compare_results
#-------------------------------------------------------------------



echo -e "---------------------------\033[33mSUMMARY\033[0m---------------------------------"
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
echo "-------------------------------------------------------------------"
echo -e "      *** View detail report in \033[36mcat/logs/main_cat_report.log\033[0m ***"
echo "-------------------------------------------------------------------"


echo "" >> main_cat_report.log
echo "---------------------------SUMMARY---------------------------------" >> main_cat_report.log
echo "SUCCESS: $COUNTER_SUCCESS" >> main_cat_report.log
echo "FAIL: $COUNTER_FAIL" >> main_cat_report.log
echo "-------------------------------------------------------------------" >> main_cat_report.log

if [ -d logs ]; then
  rm -rf ./logs/
fi

if ! [ -d logs ]; then
  mkdir ./logs/
fi

mv ./*.log ./logs/

#rm sample.txt