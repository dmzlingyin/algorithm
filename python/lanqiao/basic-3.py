rows, colums = list(input().split())
for i in range(int(rows)):
    for j in range(int(colums)):
        if j >= i:
            print(chr(j - i + 65), end='')
        else:
            print(chr(i + 65 - j), end='')
    print()