def fill(str):
    if len(str) < 5:
        return '0'*(5 - len(str)) + str
    else:
        return str

for i in range(31):
    print(fill(bin(i)[2:]))