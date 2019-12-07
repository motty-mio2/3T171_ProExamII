from random import randint

# 10 ** 100 辺りが限界かな
maxnum = 10

for i in range(10):
    a, b = randint(0, maxnum), randint(0, maxnum)
    print("int a{} = {};".format(i, a))
    print("int b{} = {};".format(i, b))
