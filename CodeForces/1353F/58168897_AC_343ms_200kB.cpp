#include <bits/stdc++.h>

using i64 = long long;

i64 n, m, T, Min, a[110][110], dp[110][110];

i64 solve(i64 x) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e18;
    dp[1][1] = a[1][1] - x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] >= x && (i != 1 || j != 1))
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - x;
    return dp[n][m];
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        Min = 1e18;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                std::cin >> a[i][j], a[i][j] -= i + j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[1][1] >= a[i][j])
                    Min = std::min(Min, solve(a[i][j]));
        std::cout << Min << std::endl;
    }
    return 0;
}
