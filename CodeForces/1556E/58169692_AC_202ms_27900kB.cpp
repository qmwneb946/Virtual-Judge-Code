#include <bits/stdc++.h>

using i64 = long long;

constexpr int maxn = 1e5 + 5;

i64 a[maxn];
int lg[maxn];
i64 mn[maxn][17], mx[maxn][17];

i64 Mn(int l, int r) {
    int len = lg[r - l + 1];
    return std::min(mn[l][len], mn[r - (1 << len) + 1][len]);
}

i64 Mx(int l, int r) {
    int len = lg[r - l + 1];
    return std::max(mx[l][len], mx[r - (1 << len) + 1][len]);
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) {
        i64 val;
        std::cin >> val;
        a[i] = -a[i] + val;
    }

    for (int i = 1; i <= n; i++) a[i] += a[i - 1], mn[i][0] = mx[i][0] = a[i];

    lg[0] = -1;
    for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;

    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        std::cin >> l >> r;

        if (a[r] - a[l - 1] != 0 || Mn(l, r) - a[l - 1] < 0) {
            std::cout << "-1\n";
            continue;
        }

        std::cout << Mx(l, r) - a[l - 1] << "\n";
    }

    return 0;
}
