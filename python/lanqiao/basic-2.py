def fill(str):
    if len(str) < 5:
        return '0'*(5 - len(str)) + str
    else:
        return str

for i in range(32):
    print(fill(bin(i)[2:]))


# for i in range(32):
#     print('{0:0>5b}'.format(i))