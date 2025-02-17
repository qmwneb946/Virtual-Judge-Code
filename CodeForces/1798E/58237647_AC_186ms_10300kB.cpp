#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 3e5 + 5;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n + 1), f(n + 1), g(n + 1), fmx(n + 2), gmx(n + 2), ans(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    auto clear = [&]() {
        for (int i = 1; i <= n; ++i) {
            f[i] = 0;
            g[i] = 0;
            fmx[i] = 0;
            gmx[i] = 0;
        }
    };
    
    clear();
    
    for (int i = n; i >= 2; --i) {
        if (i + a[i] == n) f[i] = 1;
        else if (i + a[i] < n && f[i + a[i] + 1]) f[i] = f[i + a[i] + 1] + 1;
        fmx[i] = std::max(fmx[i + 1], f[i]);
        
        if (i + a[i] >= n) g[i] = fmx[i + 1] + 1;
        else g[i] = std::max(fmx[i + 1], g[i + a[i] + 1]) + 1;
        
        gmx[i] = std::max(gmx[i + 1], g[i]);
    }

    for (int i = n - 1; i >= 1; --i) {
        if (f[i + 1]) ans[i] = a[i] != f[i + 1];
        else if (g[i + 1] >= a[i]) ans[i] = 1;
        else ans[i] = 2;
    }
    
    for (int i = 1; i < n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;
    while (T--) solve();
    
    return 0;
}