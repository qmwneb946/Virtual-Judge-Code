#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    std::vector<std::array<int, 2>> c(n);
    for (int i = 0; i < n; i++) c[i] = {a[i], b[i]};
    
    std::sort(c.begin(), c.end(), [](auto x, auto y) -> bool {
        return std::min(x[0], x[1]) < std::min(y[0], y[1]);
    });
    
    std::vector<std::vector<bool>> f(2, std::vector<bool>(2, false));
    f[0][0] = f[1][1] = true;
    
    for (int i = 1; i < n; i++) {
        std::vector<std::vector<bool>> g(2, std::vector<bool>(2, false));
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (!f[j][k]) continue;
                for (int k2 = 0; k2 < 2; k2++) {
                    if (c[i - 1][k] < c[i][k2] && c[i - 1][1 - k] < c[i][1 - k2]) {
                        g[j ^ k2][k2] = true;
                    }
                }
            }
        }
        f = g;
    }
    
    if (f[0][0] || f[0][1]) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) solve();
    
    return 0;
}
