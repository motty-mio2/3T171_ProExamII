
print("addr")
print("{")
for i in range(0, 11):
    print("{",end="")
    for j in range(0, 11):
        print(i + j, end="")
        if (j != 10):
            print(",",end="")
        #print("hello", end=",")
    print("},")
print("}")

print("multi")
print("{")
for i in range(0, 10):
    print("{", end="")
    for j in range(0, 10):
        print(str(i+j), end="")
        if (j != 9):
            print(",",end="")
    print("},")
print("}")