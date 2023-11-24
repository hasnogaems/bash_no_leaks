#!/bin/sh

# Укажите путь к  программе
PATH_PROGRAM="./s21_grep"
# Укажите путь к утилите grep
GREP="grep"

# Папка с тестовыми файлами
TEST_DIR="../common/test_files"
# Папка для результатов  программы
OUTPUT_DIR="../common/test_grep/output"
# Папка для результатов утилиты grep
GREP_OUTPUT_DIR="../common/test_grep/grep_output"

# Создаем папки для результатов, если их нет
mkdir -p "$OUTPUT_DIR"
mkdir -p "$GREP_OUTPUT_DIR"

FLAGS_TO_TEST=("-e" "-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o")
FILE="text.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$TEST_DIR/$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$TEST_DIR/$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo "File testing $FILE with flags $FLG -> \033[32msuccess\033[0m"
    else
      echo "File testing $FILE with flags $FLG -> \033[31mfail\033[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"

done

FLG="-f"
PATTERN="../common/test_files/pattern.txt"

# Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$TEST_DIR/$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$TEST_DIR/$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo "File testing $FILE with flags $FLG -> \033[32msuccess\033[0m"
    else
      echo "File testing $FILE with flags $FLG -> \033[31mfail\033[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"

FLAGS_TO_TEST=("-iv" "-ic" "-in" 
"-ih" "-vc" "-vn" "-vh" "-vs" "-vo" "-cl" "-cn" "-ch" "-cs" 
"-co" "-ln" "-lh" "-ls" "-lo" "-nh" "-ns" "-no" "-hs" "-ho" 
"-so" "-ivc" "-ivl" "-ivn" "-ivh" "-ivs" "-ivo" "-icl" "-icn" 
"-ich" "-ics" "-ico" "-iln" "-ilh" "-ils" "-ilo" "-inh" "-ins" 
"-ihs" "-vcl" "-vcn" "-vch" "-vcs" "-vco" "-nho" "-nso" "-hso" 
"-vln" "-vlh" "-vls" "-vlo" "-vnh" "-vns" "-vno" "-vhs" "-vho" 
"-vso" "-cln" "-clh" "-cls" "-clo" "-cnh" "-cns" "-cno" "-chs" 
"-cho" "-cso" "-lnh" "-lns" "-lno" "-lhs" "-lho" "-lso" "-nhs")
FILE="text.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$TEST_DIR/$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$TEST_DIR/$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo "File testing $FILE with flags $FLG -> \033[32msuccess\033[0m"
    else
      echo "File testing $FILE with flags $FLG -> \033[31mfail\033[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done

FLAGS_TO_TEST=("-v" "-c" "-n" "-h" "-vc" "-vn" 
"-vh" "-vs" "-vo" "-cl" "-cn" "-cs" "-co" "-ln" "-lh" 
"-ls" "-lo" "-nh" "-ns" "-hs" "-ivl" "-vcl" "-vcn" "-vcs" 
"-vco" "-vln" "-vlh" "-vls" "-vlo" "-vnh" "-vns" 
"-vno" "-vhs" "-vho" "-vso" "-cln" "-cls" "-clo" 
"-cns" "-cno" "-cso" "-lnh" "-lns" "-lno" 
"-lhs" "-lho" "-lso" "-nhs")

FILE="text.txt"
FILE2="text2.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$TEST_DIR/$FILE" "$TEST_DIR/$FILE2" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$TEST_DIR/$FILE" "$TEST_DIR/$FILE2" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo "File testing $FILE and $FILE2 with flags $FLG -> \033[32msuccess\033[0m"
    else
      echo "File testing $FILE and $FILE2 with flags $FLG -> \033[31mfail\033[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done

FILE="text.txt"
FILE2="text2.txt"
PATTERN="t..t"
PATTERN2="1"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM -e $PATTERN -e $PATTERN2 $FLG "$TEST_DIR/$FILE" "$TEST_DIR/$FILE2" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP -e $PATTERN -e $PATTERN2 $FLG "$TEST_DIR/$FILE" "$TEST_DIR/$FILE2" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo "File testing $FILE and $FILE2 with flags $FLG and templates [$PATTERN], [$PATTERN2] (by flag -e)  -> \033[32msuccess\033[0m"
    else
      echo "File testing $FILE and $FILE2 with flags $FLG and templates [$PATTERN], [$PATTERN2] (by flag -e) -> \033[31mfail\033[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done
