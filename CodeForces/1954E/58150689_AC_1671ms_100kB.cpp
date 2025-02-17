#include <bits/stdc++.h>

using i64 = long long;

int main() {
// #ifndef ONLINE_JUDGE
//     assert(freopen(".in.txt", "r", stdin));
//     assert(freopen(".out.txt", "w", stdout));
// #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, maxn = 0;
    std::cin >> n;
    std::vector<i64> a(n + 1), ans(1e5 + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        maxn = std::max(maxn, a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        i64 cnt = 0;
        if (i == 1 || a[i] > a[i - 1]) cnt++;
        if (i < n && a[i + 1] > a[i]) cnt--;

        i64 l = 1, r;
        while (l <= a[i]) {
            i64 t = (a[i] - 1) / l;
            if (t) r = (a[i] - 1) / t;
            else r = a[i];

            ans[l] += cnt * (t + 1);
            if (r + 1 <= maxn) ans[r + 1] -= cnt * (t + 1);

            l = r + 1;
        }

        if (a[i] + 1 <= maxn) ans[a[i] + 1] += cnt; 
    }

    for (int i = 1; i <= maxn; ++i) {
        ans[i] += ans[i - 1];
        std::cout << ans[i] << ' ';
    }

    return 0;
}
