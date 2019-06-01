#include <bits/stdc++.h>

using namespace std;
const int N = 30, M = 100 + 5, Iter = 1e6;
double p[N], pre[N];

int main() {
    srand((unsigned) time(nullptr));
    int n, m, iter = Iter, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i)scanf("%lf", &p[i]);
    for (i = 1, pre[0] = p[0]; i < n; ++i)pre[i] = pre[i - 1] + p[i];
    int ans = 0;
    while (iter--) {
        int state = 0, cnt = 0, end = (1 << n) - 1;
        while (state != end && cnt <= m) {
            double random = double(rand()) / RAND_MAX;
            int num = lower_bound(pre, pre + n, random) - pre;
            if (num < n)state |= 1 << num;
            cnt += 1;
        }
        ans += cnt <= m ? 1 : 0;
    }
    printf("%.8lf\n", (double) ans / Iter);
    return 0;
}