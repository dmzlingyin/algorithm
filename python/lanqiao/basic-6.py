n = int(input())
res = []
for i in range(n):
    row = []
    for j in range(0, i + 1):
        if j == 0 or j == i:
            print(1,end=' ')
            row.append(1)
        else:
            v = res[i-1][j]+res[i-1][j-1]
            row.append(v)
            print(v,end=' ')
    res.append(row)
    print()