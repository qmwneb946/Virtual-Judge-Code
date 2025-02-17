#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    constexpr int MAXN = 300003;
    int T;
    std::cin >> T;
    
    while (T--) {
        int n;
        std::cin >> n;
        
        std::vector<std::vector<int>> g(n + 1);
        std::vector<int> dep(n + 1), sz(n + 1), a(n + 1);
        i64 ans1 = 0, ans2 = 0, ans3 = 0;
        
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        auto dfs = [&](auto self, int u, int fa) -> void {
            dep[u] = dep[fa] + 1;
            sz[u] = 1;
            a[dep[u]]++;
            ans1 += (n - 1LL) * dep[u];
            
            int x = 0;
            i64 y = 0;
            
            for (int v : g[u]) {
                if (v == fa) continue;
                self(self, v, u);
                sz[u] += sz[v];
                y += 1LL * sz[v] * x;
                x += sz[v];
            }
            
            ans1 -= 2 * (y + sz[u] - 1) * dep[u];
            ans3 += sz[u] - 1;
        };
        
        dfs(dfs, 1, 0);
        
        for (int i = 1, x = 0; i <= n; x += a[i++]) {
            ans2 += 1LL * i * a[i] * (x - (n - a[i] - x));
        }
        
        std::cout << ans1 - ans2 + ans3 - n * (n - 1LL) / 2 << "\n";
    }
    
    return 0;
}
