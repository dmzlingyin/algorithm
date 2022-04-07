input()
array = list(map(int, input().split()))
value = int(input())

for k, v in enumerate(array):
    if v == value:
        print(k + 1)
        exit(0)

print(-1)