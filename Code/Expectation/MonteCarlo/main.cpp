#include <bits/stdc++.h>

using namespace std;
const int N = 30, Iter = 1e7;
double p[N], pre[N];

int main() {
    int n, iter = Iter, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)scanf("%lf", &p[i]);
    for (i = 1, pre[0] = p[0]; i < n; ++i)pre[i] = pre[i - 1] + p[i];
    srand((unsigned) time(nullptr));
    long long ans = 0;
    while (iter--) {
        int state = 0, cnt = 0, end = (1 << n) - 1;
        while (state != end) {
            double random = double(rand()) / RAND_MAX;
            int num = lower_bound(pre, pre + n, random) - pre;
            if (num < n)state |= 1 << num;
            cnt += 1;
        }
        ans += (long long) cnt;
    }
    printf("%.8lf\n", (double) ans / Iter);
    return 0;
}