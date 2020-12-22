from cs50 import get_int

def main():
    pyramid_h = get_int("Height: ")
    if (pyramid_h >=1) and (pyramid_h <=8):
        row_height = 1
        for i in range(pyramid_h):
            mario_left(pyramid_h, row_height)
            row_height +=1
    else:
        exit()

def mario_left(pyramid_h, row_height):
    for i in range(pyramid_h - row_height):
        print(" ", end ="")

    for j in range(row_height):
        print("#", end ="")

    print("  ", end ="")

    for k in range(row_height):
        print("#", end = "")

    for l in range(pyramid_h - row_height):
        print(" ", end = "")
    print("\n", end="")

main()