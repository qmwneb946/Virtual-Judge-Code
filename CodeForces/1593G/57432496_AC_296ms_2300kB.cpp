#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s; std::cin >> s;
    int n = s.size(), q; s = " " + s;
    std::vector <int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i] == '[' || s[i] == ']') * ((i & 1) ? 1 : -1);
    }
    std::cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << abs(sum[l - 1] - sum[r]) << std::endl;
    }
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
    while (t--) {
        solve();
    }
    return 0;
}
