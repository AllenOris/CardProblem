from __future__ import division
import random

cnt = 1
N = int(1e6)
inName = "%02d.in"
outName = "%02d.out"


def getAns(n):
    return n * sum([1 / float(i) for i in range(1, n + 1)])


for i in range(1, 20 + 1):
    n = 5 if i == 1 else random.randint(1, N)
    with open(inName % i, "w")as w:
        w.write(str(n))
    with open(outName % i, "w")as w:
        w.write(str(getAns(n)) + '\n')
