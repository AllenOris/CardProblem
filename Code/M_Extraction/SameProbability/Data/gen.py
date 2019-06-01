# -*- coding: utf-8 -*-
from __future__ import division
import random
import numpy as np


def getAns(n, m, p):
    dp = [[.0 for i in range(m + 1)] for j in range(1 << n)]
    sum = [.0 for _ in range(1 << n)]
    for s in range(0, 1 << n):
        for i in range(n):
            if not (s & (1 << i)):
                sum[s] += p[i]
        sum[s] = 1 - sum[s]
    dp[0][0] = 1.
    for i in range(1, m + 1):
        for s in range(0, 1 << n):
            dp[s][i] = dp[s][i - 1] * sum[s]
            for j in range(n):
                if s & (1 << j):
                    e = (~((~s) | (1 << j))) & s
                    dp[s][i] += dp[e][i - 1] * p[j]
    ans = .0
    for i in range(n, m + 1):
        s = (1 << n) - 1
        for j in range(n):
            e = (~((~s) | (1 << j))) & s
            ans += dp[e][i - 1] * p[j]
    return ans


inName = "%02d.in"
outName = "%02d.out"
N = 15
M = 100

for cnt in range(1, 20 + 1):
    with open(inName % cnt, "w")as w:
        n = random.randint(1, N)
        m = random.randint(1, M)
        print(cnt, ' ', n, m)
        w.write(str(n) + ' ' + str(m) + '\n')
        p = [1 / n for i in range(n)]
        ans = getAns(n, m, p)
        with open(outName % cnt, 'w')as w:
            w.write(str(ans) + '\n')
