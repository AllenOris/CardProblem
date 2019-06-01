#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; ++i)ans += 1 / (double) i;
    ans *= n;
    printf("%.8lf\n", ans);
    return 0;
}