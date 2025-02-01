#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr i64 INF = 1e15 + 1;
    
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> a[i][j];
            }
        }

        auto get = [&](int i, int j, int add) -> i64 {
            int tmp = (j + add) % m;
            return tmp == 0 ? a[i][m] : a[i][tmp];
        };

        std::vector<std::vector<std::vector<i64>>> dp(n + 1, std::vector<std::vector<i64>>(m + 1, std::vector<i64>(m, INF)));
        std::vector<std::vector<i64>> mdp(n + 1, std::vector<i64>(m + 1, INF));

        mdp[0][1] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int x = 0; x < m; ++x) {
                    dp[i][j][x] = std::min(dp[i][j][x], mdp[i - 1][j] + get(i, j, x) + 1LL * x * k);
                    dp[i][j][x] = std::min(dp[i][j][x], dp[i][j - 1][x] + get(i, j, x));
                    mdp[i][j] = std::min(mdp[i][j], dp[i][j][x]);
                }
            }
        }

        std::cout << mdp[n][m] << '\n';
    }

    return 0;
}
