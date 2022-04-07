nums = int(input())
for i in range(nums):
    s = str(input())
    s = int(s, 16)
    s = oct(s)
    print(s[2:])