#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 maxn = 200000;
constexpr i64 N = maxn + 10;

i64 n, m, ans, a[N], s[N];
bool f[N];
std::bitset<N> dp;

int main() {
#ifdef qmwneb
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    s[0] = 0;
    for (i64 i = 1; i <= n; ++i) {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    dp[1] = 1;
    for (i64 i = 1; i <= n; ++i) {
        dp = (dp | (dp << a[i]));
        f[i] = dp[i];
        dp[i] = 0;
    }

    for (i64 i = n + 1; i <= 2 * n; ++i) {
        f[i] = dp[i];
        s[i] = s[i - 1];
    }

    ans = 0;
    for (i64 i = 1; i <= 2 * n; ++i) {
        if (f[i]) {
            ans = std::max(ans, s[i] - i + 1);
        }
    }

    std::cout << ans;
    return 0;
}
