#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r, mid, n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1);
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, 0));
    std::vector<std::vector<bool>> vis(2, std::vector<bool>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    auto dfs = [&](auto self, int x, int k) -> int {
        if (x < 0 || k < 0 || m * k > x) return -1e9;
        if (x == 0) return 0;
        int t = k - (x - 1) / m;
        if (vis[t][x]) return dp[t][x];
        vis[t][x] = 1;
        return dp[t][x] = std::max(self(self, x - 1, k) + b[x], self(self, x - m, k - 1));
    };

    auto check = [&](int x) -> bool {
        for (int i = 1; i <= n; i++) b[i] = (a[i] >= x ? 1 : -1);
        for (int i = 1; i <= n; i++) vis[0][i] = vis[1][i] = 0;
        return dfs(dfs, n, (n - 1) / m) > 0;
    };

    for (l = 1, r = 1e9, mid = 0; l < r; check(mid = (l + r + 1) >> 1) ? l = mid : r = mid - 1)
        ;

    std::cout << l << '\n';
}

int main() {
#ifdef qmwneb
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
