#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5005;

int n, m, a[N], s[N], f[N][N], g[N][N];
std::vector<int> e[N];

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    std::cin >> f[1][1] >> g[1][1];

    for (int i = 2, fa; i <= n; ++i) {
        std::cin >> f[i][1] >> g[i][1] >> fa;
        e[fa].push_back(i);
    }

    for (int i = n; i; --i) {
        std::fill(f[i] + 2, f[i] + n + 1, 1.01e9);
        std::fill(g[i] + 2, g[i] + n + 1, 1.01e9);
        s[i] = 1;
        g[i][1] = f[i][1] - g[i][1];

        for (int v : e[i]) {
            for (int x = s[i]; x >= 0; --x) {
                for (int y = s[v]; y >= 0; --y) {
                    f[i][x + y] = std::min(f[i][x + y], f[i][x] + f[v][y]);
                    if (x) {
                        g[i][x + y] = std::min(g[i][x + y], g[i][x] + g[v][y]);
                    }
                }
            }
            s[i] += s[v];
        }

        for (int x = 1; x <= s[i]; ++x) {
            g[i][x] = std::min(g[i][x], f[i][x]);
        }
    }

    std::cout << (int)(std::upper_bound(g[1] + 1, g[1] + n + 1, m) - g[1] - 1) << '\n';

    return 0;
}
