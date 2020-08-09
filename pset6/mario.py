from cs50 import get_int

while True:
    # Take input until it is vaild
    try:
        n = get_int("Height: ")
        if 9 > n > 0:
            break
    except:
        pass

for i in range(1, n + 1):
    # first half of pyramid
    print(' ' * (n - i) + '#' * i, end="  ")
    # Second half ofpyramid
    print('#' * i)
