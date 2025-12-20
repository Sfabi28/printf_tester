#!/bin/bash

SOURCE_PATH="../"


TESTER_NAME="ft_printf_tester"

GREEN='\033[92m'
RED='\033[91m'
CYAN='\033[96m'
YELLOW='\033[93m'
RESET='\033[0m'
MAGENTA='\033[95m'
BLUE='\033[94m'

run_printf_tests() {
    MODE=$1
    
    echo -e "\n${BLUE}**************************************************${RESET}"
    echo -e "${BLUE}        STARTING MODE: $MODE PART                 ${RESET}"
    echo -e "${BLUE}**************************************************${RESET}\n"

    if [ "$MODE" == "BONUS" ]; then
        MAKE_RULE="bonus"
        TESTS_DIR="bonus_tests" 
    else
        MAKE_RULE="all"
        TESTS_DIR="mandatory_tests" 
    fi

    echo -e "${CYAN} Compiling Library ($MAKE_RULE)...${RESET}"
    make $MAKE_RULE -C "$SOURCE_PATH" > /dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Make failed in $SOURCE_PATH${RESET}"
        exit 1
    fi

    cc main.c "$TESTS_DIR"/*.c -L"$SOURCE_PATH" -lftprintf -I. -I"$SOURCE_PATH" -o "$TESTER_NAME"
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Tester compilation failed!${RESET}"
        exit 1
    fi
    
    echo -e "${CYAN}[3] Running Tests...${RESET}"
    for i in {1..160}; do

        ./"$TESTER_NAME" orig $i > out_orig.txt 2> ret_orig.txt
        
        valgrind -q --leak-check=full --show-leak-kinds=all --log-file=valgrind_log.txt \
            ./"$TESTER_NAME" user $i > out_user.txt 2> ret_user.txt
        
        PY_RESULT=$(python3 checker.py)
        
        echo -n "Test $i: $PY_RESULT "


        if [ -s valgrind_log.txt ] && grep -qE "definitely lost|indirectly lost|invalid read|invalid write|uninitialised" valgrind_log.txt; then
             echo -e "${RED}[MKO]${RESET}"
        fi
    done
    
    rm -f valgrind_log.txt

    rm -f out_orig.txt out_user.txt ret_orig.txt ret_user.txt "$TESTER_NAME"
}

echo -e "\n${CYAN}=== PRINTF TESTER ===${RESET}"

if [ "$1" == "b" ]; then
    run_printf_tests "BONUS"
elif [ "$1" == "" ]; then
    run_printf_tests "MANDATORY"
    run_printf_tests "BONUS"
elif [ "$1" == "m" ]; then
    run_printf_tests "MANDATORY"
else
    echo -e "${YELLOW}(Default: MANDATORY)${RESET}"
    run_printf_tests "MANDATORY"
fi
echo -e "\n${CYAN}=== DONE ===${RESET}"