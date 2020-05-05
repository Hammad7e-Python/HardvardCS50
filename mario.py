from cs50 import get_int

def func():
    while True:
        H = get_int("Height: ")
        W = H
        if H >= 0 and H <= 23:
            break

    for ixx in range(1, H + 1):
        no_of_hashes = ixx
        num_of_spaces = W - no_of_hashes

        print(" " * num_of_spaces, end="")
        print("#" * no_of_hashes, end="")

        print("  ", end="")

        print("#" * no_of_hashes)


if __name__ == "__main__":
    func()