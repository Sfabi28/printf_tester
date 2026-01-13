#!/bin/bash

SOURCE_PATH="../"
TIME=3 #(valgrind has x3)



TESTER_NAME="ft_printf_tester"
LOG_FILE="test_results.log"

GREEN='\033[92m'
RED='\033[91m'
CYAN='\033[96m'
YELLOW='\033[93m'
RESET='\033[0m'
MAGENTA='\033[95m'
BLUE='\033[94m'
WHITE='\033[97m'

check_dev_mode() {
    CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD 2>/dev/null)

    if [ "$CURRENT_BRANCH" == "dev" ]; then
        echo -e "\n${MAGENTA}⚠️  WARNING: YOU ARE IN DEVELOPER MODE (dev branch) ⚠️${NC}"
        echo -e "${MAGENTA}This version might be unstable.${NC}"
        echo -e "If you are a student, please switch to stable: ${CYAN}git checkout main${NC}\n"
        sleep 5
    fi
}

check_updates() {
    if [ -d ".git" ]; then
        echo -n -e "${CYAN}Checking for updates... ${NC}"
        
        git fetch origin > /dev/null 2>&1
        
        LOCAL=$(git rev-parse HEAD)
        REMOTE=$(git rev-parse @{u} 2>/dev/null)

        if [ -z "$REMOTE" ]; then
            return
        fi

        if [ "$LOCAL" != "$REMOTE" ]; then
            echo -e "${RED}[UPDATE FOUND]${NC}"
            echo -e "\n${YELLOW}🚨  A NEW VERSION IS AVAILABLE!  🚨${NC}"
            echo -e "You are using an old version of the tester."
            echo -e "Do you want to update it now? (Recommended) [y/N]"
            read -r -p "Select: " RESPONSE
            
            if [[ "$RESPONSE" =~ ^[yY]$ ]]; then
                echo -e "${GREEN}Downloading updates...${NC}"
                git pull
                echo -e "\n${GREEN}✅ Update successful!${NC}"
                echo -e "${CYAN}Please restart the tester to apply changes.${NC}"
                exit 0
            else
                echo -e "${YELLOW}Update skipped. Continuing with current version...${NC}\n"
            fi
        else
            echo -e "${GREEN}[UP TO DATE]${NC}"
        fi
    fi
}

check_dev_mode
check_updates

echo "=== TEST SESSION STARTED: $(date) ===" > "$LOG_FILE"
echo "Detailed logs below." >> "$LOG_FILE"
echo "-----------------------------------" >> "$LOG_FILE"
echo ""

echo -e "${CYAN} Checking Norminette...${RESET}"

TESTER_DIR=$(basename "$PWD")
FILES_TO_CHECK=$(find "$SOURCE_PATH" -type f \( -name "*.c" -o -name "*.h" \) | grep -v "/$TESTER_DIR/" | tr '\n' ' ')

if [ -z "$FILES_TO_CHECK" ]; then
    NORM_OUT=""
else
    NORM_OUT=$(norminette $FILES_TO_CHECK | grep -v "OK!" | grep -v "Error: ")
fi

if [ -z "$NORM_OUT" ]; then
    echo -e "${GREEN}[NORM OK]${RESET}"
else
    echo -e "${RED}[NORM KO]${RESET}"
    echo "$NORM_OUT"
    echo "--- NORMINETTE ERRORS ---" >> "$LOG_FILE"
    echo "$NORM_OUT" >> "$LOG_FILE"
    echo "-------------------------" >> "$LOG_FILE"
fi
echo ""

check_allowed_function() {
    echo -e "\n${BLUE}=== ALLOWED FUNCTIONS CHECK ===${RESET}"
    
    WHITELIST_FILE=".whitelist.txt"
    LIB_PATH="${SOURCE_PATH:-../}"
    BINARY="${LIB_PATH%/}/libftprintf.a"

    if [ ! -f "$BINARY" ]; then
        echo -e "${RED}Error: Library file '$BINARY' not found!${RESET}"
        return
    fi

    UNDEFINED_FUNCS=$(nm -u "$BINARY" | grep -v ":" | awk '{print $NF}' | sort | uniq)
    
    MY_FUNCS=$(nm "$BINARY" | grep -v ":" | grep -E " [Tt] " | awk '{print $NF}' | sed 's/^_//' | sort | uniq)

    VIOLATION=0
    
    if [ ! -f "$WHITELIST_FILE" ]; then
        echo -e "${YELLOW}Warning: $WHITELIST_FILE not found. Skipping check.${RESET}"
        return
    fi

    ALLOWED_FUNCS=$(cat "$WHITELIST_FILE")

    for func in $UNDEFINED_FUNCS; do

        clean_func=${func%%@*}
        clean_func=${clean_func#_}

        if [[ -z "$clean_func" || "$clean_func" == .* ]]; then
            continue
        fi

        if [[ "$clean_func" == "dyld_stub_binder" || "$clean_func" == "gmon_start" || \
              "$clean_func" == "data_start" || "$clean_func" == "edata" || \
              "$clean_func" == "end" || "$clean_func" == "bss_start" || \
              "$clean_func" == "stack_chk_fail" || "$clean_func" == "_stack_chk_fail" ]]; then
            continue
        fi

        if echo "$MY_FUNCS" | grep -F -x -q "$clean_func"; then
            continue
        fi

        if ! echo "$ALLOWED_FUNCS" | grep -F -x -q "$clean_func"; then
            echo -e "${RED}Forbidden function used: $clean_func${RESET}"
            VIOLATION=1
        fi
    done

    if [ $VIOLATION -eq 0 ]; then
        echo -e "No Forbidden Functions. ${GREEN}[OK]${RESET}"
    else
        echo -e "${RED}Forbidden functions detected!${RESET}"
        if [ -n "$LOG_FILE" ]; then
            echo "FORBIDDEN FUNCTIONS DETECTED" >> "$LOG_FILE"
        fi
    fi
}

run_printf_tests() {
    MODE=$1
    USE_VALGRIND=$2 
    
    echo ""
    echo -e "\n${BLUE}**************************************************${RESET}"
    echo -e "${BLUE}        STARTING MODE: $MODE PART                 ${RESET}"
    echo -e "${BLUE}**************************************************${RESET}\n"
    echo -e "\n\n>>> STARTING $MODE PART <<<\n" >> "$LOG_FILE"

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

    check_allowed_function

    if [ "$MODE" == "BONUS" ] && [ ! -d "bonus_tests" ]; then
         echo -e "${RED}Error: 'bonus_tests' directory missing!${RESET}"
         exit 1
    fi

    cc -w $DEFINE_FLAG main.c $TEST_FILES -L"$SOURCE_PATH" -lftprintf -I. -I"$SOURCE_PATH" -o "$TESTER_NAME"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error: Tester compilation failed!${RESET}"
        exit 1
    fi
    
    echo -e "${CYAN} Running Tests... (Logs appending to $LOG_FILE)${RESET}"
    if [ "$USE_VALGRIND" == "yes" ]; then
        echo -e "${MAGENTA}    (Valgrind Active)${RESET}"
    fi

    for i in $(seq 1 $MAX_TESTS); do

        if [ "$MODE" == "MANDATORY" ]; then
            case $i in
                1)   CURRENT_CAT="%c"; echo -e "\n${WHITE}--- Tests for %c ---${RESET}" ;;
                16)  CURRENT_CAT="%s"; echo -e "\n\n${WHITE}--- Tests for %s ---${RESET}" ;;
                31)  CURRENT_CAT="%p"; echo -e "\n\n${WHITE}--- Tests for %p ---${RESET}" ;;
                46)  CURRENT_CAT="%d"; echo -e "\n\n${WHITE}--- Tests for %d ---${RESET}" ;;
                61)  CURRENT_CAT="%i"; echo -e "\n\n${WHITE}--- Tests for %i ---${RESET}" ;;
                76)  CURRENT_CAT="%u"; echo -e "\n\n${WHITE}--- Tests for %u ---${RESET}" ;;
                91)  CURRENT_CAT="%x"; echo -e "\n\n${WHITE}--- Tests for %x ---${RESET}" ;;
                106) CURRENT_CAT="%X"; echo -e "\n\n${WHITE}--- Tests for %X ---${RESET}" ;;
                121) CURRENT_CAT="%%"; echo -e "\n\n${WHITE}--- Tests for %% ---${RESET}" ;;
                131) CURRENT_CAT="Mix"; echo -e "\n\n${WHITE}--- Mixed Tests ---${RESET}" ;;
            esac
        elif [ "$MODE" == "BONUS" ]; then
            case $i in
                1)   CURRENT_CAT="Bonus -"; echo -e "\n${WHITE}--- Bonus: Minus Flag (-) ---${RESET}" ;;
                26)  CURRENT_CAT="Bonus 0"; echo -e "\n\n${WHITE}--- Bonus: Zero Flag (0) ---${RESET}" ;;
                51)  CURRENT_CAT="Bonus ."; echo -e "\n\n${WHITE}--- Bonus: Dot Precision (.) ---${RESET}" ;;
                76)  CURRENT_CAT="Bonus #"; echo -e "\n\n${WHITE}--- Bonus: Hash Flag (#) ---${RESET}" ;;
                101) CURRENT_CAT="Bonus Space"; echo -e "\n\n${WHITE}--- Bonus: Space ( ) ---${RESET}" ;;
                126) CURRENT_CAT="Bonus +"; echo -e "\n\n${WHITE}--- Bonus: Plus Flag (+) ---${RESET}" ;;
                151) CURRENT_CAT="Bonus Combo"; echo -e "\n\n${WHITE}--- Bonus: Multiple Flags ---${RESET}" ;;
            esac
        fi

        ./"$TESTER_NAME" orig $i $TYPE_FLAG > out_orig.txt 2> ret_orig.txt
        
        if [ "$USE_VALGRIND" == "yes" ]; then
            CURRENT_TIME=$((TIME * 3))
        else
            CURRENT_TIME=$TIME
        fi

        if [ "$USE_VALGRIND" == "yes" ]; then
            (timeout ${CURRENT_TIME} valgrind -q --leak-check=full --show-leak-kinds=all --log-file=valgrind_log.txt \
                ./"$TESTER_NAME" user $i $TYPE_FLAG > out_user.txt 2> ret_user.txt) 2>/dev/null
            EXIT_CODE=$?
        else
            (timeout ${CURRENT_TIME} ./"$TESTER_NAME" user $i $TYPE_FLAG > out_user.txt 2> ret_user.txt) 2>/dev/null
            EXIT_CODE=$?
        fi

        if [ $EXIT_CODE -eq 124 ]; then
            echo -n -e "${RED}[TIMEOUT]${RESET} "
            echo "Test $i: TIMEOUT (Infinite Loop?)" >> "$LOG_FILE"
            continue
        elif [ $EXIT_CODE -eq 139 ]; then
            echo -n -e"${RED}[SIGSEGV]${RESET} "
            echo "Test $i: CRASH (Segmentation Fault)" >> "$LOG_FILE"
            continue
        fi

        PY_RESULT=$(python3 $CHECKER "$i" "$CURRENT_CAT")
        echo -n "$i:$PY_RESULT "

        if [ "$USE_VALGRIND" == "yes" ]; then
            if [ -s valgrind_log.txt ] && grep -qE "definitely lost|indirectly lost|invalid read|invalid write|uninitialised" valgrind_log.txt; then
                 echo -n -e "${RED}[MKO]${RESET} "
            else
                 : 
            fi
        fi
    done
    
    echo "" 
    rm -f valgrind_log.txt
    rm -f out_orig.txt out_user.txt ret_orig.txt ret_user.txt "$TESTER_NAME"

    echo -e "\n${CYAN}Cleaning up library (fclean)...${RESET}"
    make fclean -C "$SOURCE_PATH" > /dev/null
    echo -e "${GREEN}Cleanup Done!${RESET}"
    echo -e "${YELLOW}Check $LOG_FILE for full results (Mandatory + Bonus).${RESET}"
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