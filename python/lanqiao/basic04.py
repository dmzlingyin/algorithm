n = int(input())

def fib(n):
    if n == 0 or n == 1:
        return n
    dp_i_1 = 1
    dp_i_2 = 0
    for i in range(2, n+1):
        dp_i = dp_i_1 + dp_i_2
        dp_i_2 = dp_i_1
        dp_i_1 = dp_i
    return dp_i_1

fn = fib(n)
print(fn % 10007)