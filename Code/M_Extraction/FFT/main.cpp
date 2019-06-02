#include <bits/stdc++.h>

using namespace std;
#define double long double

const int M = 500, N = 25;
const double pi = acos(-1);
typedef complex<double> C;
int g[M];
C a[M], b[M];
double c[M], p[M], fab[M];
int n, m;

void FFT(C *a, int N, int f = 1) {
    int i, j, k, p;
    for (i = 0; i < N; ++i) if (g[i] > i)swap(a[i], a[g[i]]);
    for (i = 1; i < N; i <<= 1) {
        C e(cos(pi / i), f * sin(pi / i));
        for (j = 0; j < N; j += i << 1) {
            C w(1, 0);
            for (k = 0; k < i; ++k) {
                C x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
                w *= e;
            }
        }
    }
    if (f < 0)for (i = 0; i < N; ++i)a[i].real(a[i].real() / N);
}

void mul(C *a, C *b, double *c, int k, int need = 0) {
    if (need == 0)need = k;
    int i, p = int(ceil(log(k << 1) / log(2)));
    int P = 1 << p;
    for (i = 1; i < P; ++i) {
        g[i] = g[i >> 1] >> 1 | ((i & 1) << (p - 1));
    }
    FFT(a, P), FFT(b, P);
    for (i = 0; i < P; ++i) a[i] = a[i] * b[i];
    FFT(a, P, -1);
    for (i = 0; i <= need; ++i) c[i] = a[i].real();
}

int main() {
//    freopen("../../Data/sample.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> p[i];

    //计算抽空的概率
    double emp = 0;
    for (int i = 0; i < n; ++i)emp += p[i];
    emp = 1 - emp;

    fab[0] = 1;
    for (int i = 1; i <= m; ++i)fab[i] = fab[i - 1] * i;

    double ans = 0;
    for (int i = 0; i < n; ++i) { //枚举最后一种抽到的卡片
        memset(a, 0, sizeof(a));
        a[0].real(1.0);
        for (int j = 0; j < n; ++j) {
            if (i == j)continue;
            memset(b, 0, sizeof(b));
            double pw = 1;
            for (int k = 1; k <= m; ++k) {
                pw *= p[j];
                b[k].real(pw / fab[k]);
            }
            mul(a, b, c, m);
        }
        // 抽空的情况考虑
        memset(b, 0, sizeof(b));
        double pw = 1;
        b[0].real(1);
        for (int k = 1; k <= m; ++k) {
            pw *= emp;
            b[k].real(pw / fab[k]);
        }
        mul(a, b, c, m);
        for (int j = n - 1; j <= m - 1; ++j) {
           ans += fab[j] * c[j] * p[i];
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(8) << ans << endl;
    return 0;
}