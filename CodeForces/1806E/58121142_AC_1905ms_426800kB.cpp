#include <bits/stdc++.h>

using i64 = long long;

constexpr int mxn = 1e5 + 5;

int n, q;
std::vector<i64> a(mxn), d(mxn), c(mxn), p(mxn), fa(mxn), s(mxn);
std::vector <std::vector <i64>> f(mxn, std::vector<i64>(500));

i64 dfs(int x, int y) {
    if (x == y) return s[x];
    if (c[d[x]] < 500) {
        if (f[x][p[y]]) return f[x][p[y]];
        return f[x][p[y]] = dfs(fa[x], fa[y]) + (i64)a[x] * a[y];
    } else
        return dfs(fa[x], fa[y]) + (i64)a[x] * a[y];
}

int main() {
#ifndef ONLINE_JUDGE
     assert(freopen(".in.txt", "r", stdin));
     assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 2; i <= n; ++i) std::cin >> fa[i];

    for (int i = 1; i <= n; ++i) {
        s[i] = s[fa[i]] + (i64)a[i] * a[i];
        d[i] = d[fa[i]] + 1;
        p[i] = ++c[d[i]];
    }

    int x, y;
    while (q--) {
        std::cin >> x >> y;
        std::cout << dfs(x, y) << "\n";
    }

    return 0;
}