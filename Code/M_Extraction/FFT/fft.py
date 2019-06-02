# python精度控制
from __future__ import division
from math import *
from decimal import *

getcontext().prec = 1000
N, M = 25, 256
g = [0 for i in range(M)]
c = [Decimal(0.) for i in range(M)]


class C:
    def __init__(self, real, imag=Decimal(0.)):
        self.real = Decimal(real)
        self.imag = Decimal(imag)

    def __add__(self, other):
        return C(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        return C(self.real - other.real, self.imag - other.imag)

    def __mul__(self, other):
        a, b, c, d = self.real, self.imag, other.real, other.imag
        return C(a * c - b * d, b * c + a * d)


def FFT(a, N, f=1):
    for i in range(N):
        if g[i] > i:
            a[i], a[g[i]] = a[g[i]], a[i]
    i = 1
    while i < N:
        e = C(Decimal(cos(Decimal(pi) / i)), Decimal(f * Decimal(sin(Decimal(pi) / i))))
        for j in range(0, N, i << 1):
            w = C(Decimal(1), Decimal(0))
            for k in range(i):
                x, y = a[j + k], w * a[j + k + i]
                a[j + k], a[j + k + i] = x + y, x - y
                w = w * e
        i <<= 1
    if f < 0:
        for i in range(N):
            a[i] = C(Decimal(a[i].real / N), a[i].imag)


def mul(a, b, c, k, need=0):
    need = k if need == 0 else need
    p = int(ceil(log2(k << 1)))
    P = 1 << p
    for i in range(1, P):
        g[i] = (g[i >> 1] >> 1) | ((i & 1) << (p - 1))
    FFT(a, P)
    FFT(b, P)
    for i in range(P):
        a[i] = a[i] * b[i]
    FFT(a, P, -1)
    for i in range(need + 1):
        c[i] = a[i].real


if __name__ == '__main__':
    n, m = map(int, input().strip().split())
    p = list(map(Decimal, map(float, input().strip().split())))

    emp = 1 - sum(p)
    fab = [1]
    for i in range(1, m + 1):
        fab.append(fab[i - 1] * i)
    ans = Decimal(.0)
    for i in range(n):
        a = [C(Decimal(0), Decimal(0)) for i in range(M)]
        a[0] = C(Decimal(1.0))
        for j in range(n):
            if i != j:
                b = [C(0) for i in range(M)]
                pw = Decimal(1.)
                for k in range(1, m + 1):
                    pw = pw * p[j]
                    b[k] = C(Decimal(pw / fab[k]))
                    # print(pw / fab[k])
                mul(a, b, c, m)

        b = [C(Decimal(0), Decimal(0)) for i in range(M)]
        pw = Decimal(1.)
        b[0] = C(Decimal(1.))
        for k in range(1, m + 1):
            pw = pw * emp
            b[k] = C(Decimal(pw / fab[k]))
        mul(a, b, c, m)
        for j in range(n - 1, m):
            ans += Decimal(c[j] * p[i] * fab[j])
    print(ans)
