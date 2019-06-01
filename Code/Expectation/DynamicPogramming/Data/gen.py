# -*- coding: utf-8 -*-
from __future__ import division
import random
import numpy as np


def getAns(n, p):
    dp = [.0 for i in range(1 << (n + 1))]
    for s in range((1 << n) - 2, 0 - 1, -1):
        P = 0
        for i in range(n):
            if (s | (1 << i)) != s:
                P += p[i]
                dp[s] += p[i] * dp[s | (1 << i)]
        dp[s] = (1.0 + dp[s]) / P
    return dp[0]


inName = "%02d.in"
outName = "%02d.out"
N = 25

for cnt in range(1, 20 + 1):
    with open(inName % cnt, "w")as w:
        n = random.randint(1, N)
        print(cnt, ' ', n)
        w.write(str(n) + '\n')
        p = [random.randint(1, 10000) for _ in range(n)]
        P = sum(p) + random.randint(1, sum(p))
        p = [p[i] / P for i in range(n)]
        for i in range(n):
            w.write(str(p[i]) + ' ')
    ans = getAns(n, p)
    with open(outName % cnt, 'w')as w:
        w.write(str(ans) + '\n')
