#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 505;
constexpr int inf = 1e9;
constexpr i64 infll = 1e18;

struct Edge { int u, v, w; };

void solve () {
	int n, m;
	std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, inf));
    std::vector<Edge> e(m);

    for (int i = 1; i <= n; ++i) {
    	g[i][i] = 0;
    }
    
    for (int i = 0; i < m; ++i) {
        std::cin >> e[i].u >> e[i].v >> e[i].w;
        g[e[i].u][e[i].v] = g[e[i].v][e[i].u] = 1;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    i64 ans = infll;
    for (int i = 0; i < m; ++i) {
        int now = std::min({g[1][e[i].u] + g[e[i].v][n], g[1][e[i].v] + g[e[i].u][n]});
        for (int j = 1; j <= n; ++j) {
            now = std::min({now, g[e[i].u][j] + 1 + g[1][j] + g[j][n], g[e[i].v][j] + 1 + g[1][j] + g[j][n]});
        }
        ans = std::min(ans, 1ll * e[i].w * (now + 1));
    }
    
    std::cout << ans << '\n';
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
