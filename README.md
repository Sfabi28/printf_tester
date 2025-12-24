# ft_printf Tester

A comprehensive and strict tester for the 42 **ft_printf** project. It supports both Mandatory and Bonus parts, includes memory leak detection via Valgrind, and generates detailed logs for debugging.

## 📁 1. Installation

Ensure that the folder of this tester (`printf_tester`) is located **INSIDE** the root of your `ft_printf` project.

**Correct Directory Structure:**
```text
/ft_printf_root
    ├── Makefile
    ├── ft_printf.h
    ├── *.c (your source files)
    └── printf_tester/       <--- YOU ARE HERE
          ├── launch.sh
          ├── main.c
          ├── checker.py
          ├── test_results.log (generated after run)
          ├── mandatory_tests/
          └── bonus_tests/
```

**Important:** To avoid accidentally committing the tester to your repository, add `printf_tester/` to your `.gitignore` file:

```bash
echo "printf_tester/" >> .gitignore
```

Ensure that the path is right and set a proper timeout time **INSIDE** the `launch.sh` file

```text
   SOURCE_PATH="../"
   TIME=3 (valgrind has x3)
```

## 🚀 2. First Run


Before running the tester for the first time, you must grant execution permissions to the main script:

```bash
chmod +x launch.sh
```

## ⚙️ 3. Usage Commands
-----------------
The tester supports different modes and optional integration with Valgrind.

```text
Command,Description
./launch.sh,Runs ALL tests (Mandatory + Bonus).
./launch.sh m,Runs MANDATORY tests only.
./launch.sh b,Runs BONUS tests only.

Command,Description
./launch.sh val,Runs ALL tests with Valgrind checks.
./launch.sh m val,Runs MANDATORY tests with Valgrind.
./launch.sh b val,Runs BONUS tests with Valgrind.
```

## 📊 4. Results Legend
-----------------
```text
[OK]   : The printed output and the return value (ret) are identical to the original printf.
[KO]   : There is a discrepancy. Check the log file for details.

If Valgrind is active:
[MOK]  : Memory OK. No leaks and no invalid memory access errors.
[MKO]  : Memory KO. Leaks, invalid read/write, or uninitialized variables found.
```

## 📝 5. Debugging with Logs
-----------
```text
Test ID: 87 [Bonus #] -> KO
   ORIG Str: '  0xa'       <-- What printf printed
   USER Str: '0x    a'     <-- What your ft_printf printed
   ORIG Ret: 5             <-- Return value of printf
   USER Ret: 7             <-- Return value of ft_printf
```
Happy debugging!🖥️



## 🛠️ More 42 Tools

Explore my full suite of testers:

[![libft](https://img.shields.io/badge/42-libft-blue?style=for-the-badge&logo=c)](https://github.com/Sfabi28/libft_tester)
[![get_next_line](https://img.shields.io/badge/42-Get_Next_Line-green?style=for-the-badge&logo=c)](https://github.com/Sfabi28/gnl_tester)
[![push_swap](https://img.shields.io/badge/42-push__swap-orange?style=for-the-badge&logo=c)](https://github.com/Sfabi28/push_swap_tester)