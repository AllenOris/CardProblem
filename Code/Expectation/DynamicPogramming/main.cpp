#include <bits/stdc++.h>

using namespace std;

const int N = 25 + 2;
double dp[1 << N], p[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)scanf("%lf", &p[i]);
    for (int s = (1 << n) - 2; s >= 0; --s) {
        double P = 0;
        for (int i = 0; i < n; ++i) {
            if ((s | (1 << i)) != s) {
                P += p[i];
                dp[s] += p[i] * dp[s | (1 << i)];
            }
        }
        dp[s] = dp[s] / P + 1.0 / P;
    }
    printf("%.8lf\n", dp[0]);
    return 0;
}