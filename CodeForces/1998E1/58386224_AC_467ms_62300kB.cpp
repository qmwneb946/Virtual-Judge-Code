#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n, x, ans;
    std::cin >> n >> x;
    std::vector<i64> a(n + 1), s(n + 1), lg(n + 1), pre(n + 1), suf(n + 1);
    std::vector<std::vector<i64>>   fx(18, std::vector<i64>(n + 1)), 
                                    fy(18, std::vector<i64>(n + 1));
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
        fx[0][i] = a[i] + s[i];
        fy[0][i] = a[i] - s[i - 1];
    }
    auto qry1 = [&](int x, int y) {
        int l = lg[y - x + 1];
        return std::max(fx[l][x], fx[l][y - (1 << l) + 1]);
    };
    auto qry2 = [&](int x, int y) {
        int l = lg[y - x + 1];
        return std::max(fy[l][x], fy[l][y - (1 << l) + 1]);
    };

    for (int i = 1; i <= 17; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            fx[i][j] = std::max(fx[i - 1][j], fx[i - 1][j + (1 << (i - 1))]);
            fy[i][j] = std::max(fy[i - 1][j], fy[i - 1][j + (1 << (i - 1))]);
        }
    }

    ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        while (true) {
            int tl = l, tr = r;
            for (int j = 17; j >= 0; j--) {
                if (l > (1 << j) && qry1(l - (1 << j), l - 1) <= s[r]) {
                    l -= 1 << j;
                }
            }
            for (int j = 17; j >= 0; j--) {
                if (r + (1 << j) <= n && qry2(r + 1, r + (1 << j)) <= -s[l - 1]) {
                    r += 1 << j;
                }
            }
            if (l == 1 && r == n) {
                ++ans;
                break;
            }
            if (tl == l && tr == r) break;
        }
    }
    std::cout << ans << std::endl;
    return;
}

int main() {
#ifdef qmwneb
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
