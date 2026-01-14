import sys
import os

FILE_OUT_ORIG = "out_orig.txt"
FILE_OUT_USER = "out_user.txt"
FILE_RET_ORIG = "ret_orig.txt"
FILE_RET_USER = "ret_user.txt"
LOG_FILE = "test_results.log"

GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

def get_file_content(filename):
    if not os.path.exists(filename):
        return "<FILE MISSING>"
    try:
        with open(filename, "r", encoding="utf-8", errors="backslashreplace") as f:
            return f.read()
    except:
        return "<READ ERROR>"

def log_to_file(test_id, category, out_o, out_u, ret_o, ret_u, status):
    """Scrive i dettagli nel file di log."""
    
    vis_out_o = repr(out_o)
    vis_out_u = repr(out_u)

    with open(LOG_FILE, "a", encoding="utf-8") as f:
        f.write(f"Test ID: {test_id} [{category}] -> {status}\n")
        f.write(f"   ORIG Str: {vis_out_o}\n")
        f.write(f"   USER Str: {vis_out_u}\n")
        f.write(f"   ORIG Ret: {ret_o.strip()}\n")
        f.write(f"   USER Ret: {ret_u.strip()}\n")
        f.write("-" * 40 + "\n")

def check():
    test_id = sys.argv[1] if len(sys.argv) > 1 else "?"
    category = sys.argv[2] if len(sys.argv) > 2 else "Unknown"

    out_orig = get_file_content(FILE_OUT_ORIG)
    out_user = get_file_content(FILE_OUT_USER)
    ret_orig_raw = get_file_content(FILE_RET_ORIG)
    ret_user_raw = get_file_content(FILE_RET_USER)

    ret_orig = ret_orig_raw.strip()
    ret_user = ret_user_raw.strip()

    is_out_ok = (out_orig == out_user)
    is_ret_ok = (ret_orig == ret_user)

    if is_out_ok and is_ret_ok:
        print(f"{GREEN}[OK]{RESET}")
        status = "OK"
    else:
        print(f"{RED}[KO]{RESET}")
        status = "KO"

    log_to_file(test_id, category, out_orig, out_user, ret_orig, ret_user, status)

if __name__ == "__main__":
    check()