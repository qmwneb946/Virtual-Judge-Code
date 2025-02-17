#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - a[1];
    }

    constexpr int inf = 1e9 + 5;
    constexpr int N = 1e6 + 10;
    std::vector<int> dp(N, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = b[i]; j < N; j++) {
            dp[j] = std::min(dp[j], dp[j - b[i]] + 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (dp[i] <= k) {
            std::cout << k * a[1] + i << ' ';
        }
    }

    return 0;
}
