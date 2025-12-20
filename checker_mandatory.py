import sys

GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"
YELLOW = "\033[93m"

def get_file_content(filename):
    """Legge il contenuto di un file gestendo errori di encoding."""
    try:
        with open(filename, "r", encoding="utf-8", errors="backslashreplace") as f:
            return f.read()
    except FileNotFoundError:
        return None

def check():
    
    out_orig = get_file_content("out_orig.txt")
    out_user = get_file_content("out_user.txt")

    ret_orig_raw = get_file_content("ret_orig.txt")
    ret_user_raw = get_file_content("ret_user.txt")

    if out_orig is None or out_user is None or ret_orig_raw is None or ret_user_raw is None:
        print(f"{RED}[ERR: Files missing]{RESET}")
        return

    ret_orig = ret_orig_raw.strip()
    ret_user = ret_user_raw.strip()

    is_out_ok = (out_orig == out_user)
    is_ret_ok = (ret_orig == ret_user)

    if is_out_ok and is_ret_ok:
        print(f"{GREEN}[OK]{RESET}")
    else:
        print(f"{RED}[KO]{RESET}")

if __name__ == "__main__":
    check()