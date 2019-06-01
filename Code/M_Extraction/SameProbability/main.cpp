#include <bits/stdc++.h>

using namespace std;
const int N = 20 + 1, M = 100 + 5;
double p[N], pw[M];
double Stirling[M][N];
double fab[M];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fab[0] = 1;
    for (int i = 1; i <= m; ++i)fab[i] = fab[i - 1] * i;
    pw[0] = 1;
    for (int i = 1; i <= m; ++i)pw[i] = pw[i - 1] / n;
    for (int i = 1; i <= m; ++i)Stirling[i][1] = 1;
    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            Stirling[i][j] = Stirling[i - 1][j - 1] + j * Stirling[i - 1][j];
        }
    }
    double ans = 0;
    for (int i = n; i <= m; ++i) {
        double x = Stirling[i - 1][n - 1] * fab[n - 1];
        ans += x * n * pw[i];
    }
    printf("%.8lf\n", ans);
    return 0;
}