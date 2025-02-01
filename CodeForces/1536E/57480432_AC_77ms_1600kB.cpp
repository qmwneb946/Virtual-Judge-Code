#include <bits/stdc++.h>

using i64 = long long;

const int P = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int cases;
    std::cin >> cases;
    while (cases--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> a(n);
        int ans = 1;
        bool zero = false;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '0') zero = true;
                else ans = (i64) ans * 2 % P;
            }
        }
        if (!zero) ans = (ans + P - 1) % P;
        std::cout << ans << '\n';
    }

    return 0;
}