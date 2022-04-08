# import math

def my_sum(i):
    s = str(i)
    a = int(s[0])
    b = int(s[1])
    c = int(s[2])
    return a*a*a + b*b*b + c*c*c

for i in range(100, 999):
    if my_sum(i) == i:
        print(i)