#!/bin/bash

SOURCE_PATH="../"
TESTER_NAME="ft_printf_tester"

# Colori
GREEN='\033[92m'
RED='\033[91m'
CYAN='\033[96m'
YELLOW='\033[93m'
RESET='\033[0m'
MAGENTA='\033[95m'
BLUE='\033[94m'
WHITE='\033[97m'

run_printf_tests() {
    MODE=$1
    USE_VALGRIND=$2
    
    echo -e "\n${BLUE}**************************************************${RESET}"
    echo -e "${BLUE}        STARTING MODE: $MODE PART                 ${RESET}"
    echo -e "${BLUE}**************************************************${RESET}\n"

    if [ "$MODE" == "BONUS" ]; then
        MAKE_RULE="bonus"
        TEST_FILES="mandatory_tests/*.c bonus_tests/*.c"
        if [ -f "checker_bonus.py" ]; then CHECKER="checker_bonus.py"; else CHECKER="checker.py"; fi
        TYPE_FLAG="b"
        MAX_TESTS=200
        DEFINE_FLAG="-D BONUS"
    else
        MAKE_RULE="all"
        TEST_FILES="mandatory_tests/*.c"
        if [ -f "checker_mandatory.py" ]; then CHECKER="checker_mandatory.py"; else CHECKER="checker.py"; fi
        TYPE_FLAG="m"
        MAX_TESTS=160
        DEFINE_FLAG=""
    fi

    echo -e "${CYAN} Compiling Library ($MAKE_RULE)...${RESET}"
    make fclean -C "$SOURCE_PATH" > /dev/null
    make $MAKE_RULE -C "$SOURCE_PATH" > /dev/null
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Make failed in $SOURCE_PATH${RESET}"
        exit 1
    fi

    if [ "$MODE" == "BONUS" ] && [ ! -d "bonus_tests" ]; then
         echo -e "${RED}Error: 'bonus_tests' directory missing!${RESET}"
         exit 1
    fi

    cc -w $DEFINE_FLAG main.c $TEST_FILES -L"$SOURCE_PATH" -lftprintf -I. -I"$SOURCE_PATH" -o "$TESTER_NAME"
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Tester compilation failed!${RESET}"
        exit 1
    fi
    
    echo -e "${CYAN} Running Tests...${RESET}"
    if [ "$USE_VALGRIND" == "yes" ]; then
        echo -e "${MAGENTA}    (Valgrind Active)${RESET}"
    fi

    for i in $(seq 1 $MAX_TESTS); do

        if [ "$MODE" == "MANDATORY" ]; then
            case $i in
                1)   echo -e "\n${WHITE}--- Tests for %c ---${RESET}" ;;
                16)  echo -e "\n\n${WHITE}--- Tests for %s ---${RESET}" ;;
                31)  echo -e "\n\n${WHITE}--- Tests for %p ---${RESET}" ;;
                46)  echo -e "\n\n${WHITE}--- Tests for %d ---${RESET}" ;;
                61)  echo -e "\n\n${WHITE}--- Tests for %i ---${RESET}" ;;
                76)  echo -e "\n\n${WHITE}--- Tests for %u ---${RESET}" ;;
                91)  echo -e "\n\n${WHITE}--- Tests for %x ---${RESET}" ;;
                106) echo -e "\n\n${WHITE}--- Tests for %X ---${RESET}" ;;
                121) echo -e "\n\n${WHITE}--- Tests for %% ---${RESET}" ;;
                131) echo -e "\n\n${WHITE}--- Mixed Tests ---${RESET}" ;;
            esac
        elif [ "$MODE" == "BONUS" ]; then
            case $i in
                1)   echo -e "\n${WHITE}--- Bonus: Minus Flag (-) ---${RESET}" ;;
                26)  echo -e "\n\n${WHITE}--- Bonus: Zero Flag (0) ---${RESET}" ;;
                51)  echo -e "\n\n${WHITE}--- Bonus: Dot Precision (.) ---${RESET}" ;;
                76)  echo -e "\n\n${WHITE}--- Bonus: Hash Flag (#) ---${RESET}" ;;
                101) echo -e "\n\n${WHITE}--- Bonus: Space ( ) ---${RESET}" ;;
                126) echo -e "\n\n${WHITE}--- Bonus: Plus Flag (+) ---${RESET}" ;;
                151) echo -e "\n\n${WHITE}--- Bonus: Multiple Flags ---${RESET}" ;;
            esac
        fi

        ./"$TESTER_NAME" orig $i $TYPE_FLAG > out_orig.txt 2> ret_orig.txt
        
        if [ "$USE_VALGRIND" == "yes" ]; then
            valgrind -q --leak-check=full --show-leak-kinds=all --log-file=valgrind_log.txt \
                ./"$TESTER_NAME" user $i $TYPE_FLAG > out_user.txt 2> ret_user.txt
        else
            ./"$TESTER_NAME" user $i $TYPE_FLAG > out_user.txt 2> ret_user.txt
        fi

        PY_RESULT=$(python3 $CHECKER)
        echo -n "$i:$PY_RESULT "

        if [ "$USE_VALGRIND" == "yes" ]; then
            if [ -s valgrind_log.txt ] && grep -qE "definitely lost|indirectly lost|invalid read|invalid write|uninitialised" valgrind_log.txt; then
                 echo -n "${RED}[MKO]${RESET} "
            else
                 : 
            fi
        fi
    done
    
    echo "" 
    rm -f valgrind_log.txt
    rm -f out_orig.txt out_user.txt ret_orig.txt ret_user.txt "$TESTER_NAME"

    echo -e "\n${CYAN} Cleaning up library (fclean)...${RESET}"
    make fclean -C "$SOURCE_PATH" > /dev/null
    echo -e "${GREEN}Cleanup Done!${RESET}"
}

ARG_MODE=""
ARG_VAL="no"

if [ "$1" == "val" ]; then
    ARG_VAL="yes"
elif [ "$1" == "m" ] || [ "$1" == "b" ]; then
    ARG_MODE="$1"
    if [ "$2" == "val" ]; then
        ARG_VAL="yes"
    fi
fi

echo -e "\n${CYAN}=== PRINTF TESTER ===${RESET}"

if [ "$ARG_MODE" == "b" ]; then
    run_printf_tests "BONUS" "$ARG_VAL"
elif [ "$ARG_MODE" == "m" ]; then
    run_printf_tests "MANDATORY" "$ARG_VAL"
else
    echo -e "${YELLOW}(Default: MANDATORY + BONUS)${RESET}"
    run_printf_tests "MANDATORY" "$ARG_VAL"
    run_printf_tests "BONUS" "$ARG_VAL"
fi

echo -e "\n${CYAN}=== DONE ===${RESET}"