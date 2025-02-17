#include <bits/stdc++.h>
using i64 = long long;

int n, mxd, U, fa[2020];
std::vector<int> G[2020];

void dfs(int u, int f, int d) {
    if (d > mxd) {
        mxd = d;
        U = u;
    }
    for (int v : G[u]) {
        if (v == f) continue;
        fa[v] = u;
        dfs(v, u, d + 1);
    }
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
        std::cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    mxd = 0;
    dfs(1, -1, 1);
    mxd = 0;
    int s = U;
    dfs(U, -1, 1);
    int t = U;

    std::vector<int> vc;
    for (int i = t; i != s; i = fa[i]) {
        vc.push_back(i);
    }
    vc.push_back(s);

    if (vc.size() % 4) {
        std::cout << vc.size() / 2 + 1 << '\n';
        for (int i = 0; i <= vc.size() / 2; ++i) {
            std::cout << vc[vc.size() / 2] << ' ' << i << '\n';
        }
    } else {
        std::cout << vc.size() / 2 << '\n';
        int x = vc[vc.size() / 2 - 1], y = vc[vc.size() / 2];
        for (int i = 0; i < vc.size() / 4; ++i) {
            std::cout << x << ' ' << i * 2 + 1 << '\n' << y << ' ' << i * 2 + 1 << '\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
