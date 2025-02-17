#include <bits/stdc++.h>

using i64 = long long;

i64 qpow(i64 x, i64 y, i64 mod) {
    if (y == 0) return 1;
    if (y == 1) return x;
    i64 res = qpow(x, y / 2, mod);
    if (y & 1) return res * res % mod * x % mod;
    else return res * res % mod;
}

void solve() {
    int n, k, cnt_done = 0, cnt_undo = 0;
    std::cin >> n >> k;
    std::vector<int> a(n + 1, 1e9);

    for (int i = 0; i <= n; i++) {
        std::string s;
        std::cin >> s;
        if (s != "?") {
            cnt_done++;
            a[i] = std::stoi(s);
        } else {
            cnt_undo++;
        }
    }

    if (k == 0) {
        if (a[0] == 1e9) {
            std::cout << ((cnt_done & 1) ? "Yes" : "No") << std::endl;
        } else {
            std::cout << (a[0] == 0 ? "Yes" : "No") << std::endl;
        }
        return;
    }
    if (cnt_done == n + 1) {
        auto f = [&](i64 mod) {
            i64 sum = 0;
            for (int i = 0; i <= n; i++) {
                sum = (sum + qpow(k, i, mod) * a[i] % mod + mod) % mod;
            }
            return sum;
        };

        if (f(993244853) == 0 && f(1e9 + 9) == 0 && f(1e9 + 7) == 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    } else {
        std::cout << (n & 1 ? "Yes\n" : "No\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
