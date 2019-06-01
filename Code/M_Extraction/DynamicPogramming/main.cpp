#include <bits/stdc++.h>

using namespace std;

const int N = 20 + 1, M = 100 + 5;
double dp[1 << N][M], sum[1 << N], p[N];

int main() {
//    freopen("../../Data/sample.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)scanf("%lf", &p[i]);
    // 预处理每个状态的概率和
    for (int s = 0; s < (1 << n); ++s) {
        for (int i = 0; i < n; ++i) {
            if (!(s & (1 << i)))sum[s] += p[i];
        }
        sum[s] = 1 - sum[s];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int s = 0; s < (1 << n); ++s) {
            dp[s][i] = dp[s][i - 1] * sum[s];// 自环的情况
            for (int j = 0; j < n; ++j) {
                if (s & (1 << j)) {
                    int e = (~((~s) | (1 << j))) & s;
                    dp[s][i] += dp[e][i - 1] * p[j];
                }
            }
        }
    }
    double ans = 0;
    for (int i = n; i <= m; ++i) {
        int s = (1 << n) - 1;
        for (int j = 0; j < n; ++j) {
            int e = (~((~s) | (1 << j))) & s;
            ans += dp[e][i - 1] * p[j];
        }
    }
    printf("%.8lf\n", ans);
    return 0;
}