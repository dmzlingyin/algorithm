def reverse(i):
    return str(i)[1] + str(i)[0]

for i in range(10, 100):
    print(str(i) + reverse(i))

