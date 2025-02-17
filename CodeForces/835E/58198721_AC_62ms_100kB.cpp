#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y, k, a, b, ab = 0;
    std::vector<int> p[11], t;

    auto query = [&](std::vector<int> q) -> bool {
        std::cout << "? " << q.size();
        for (int u : q) std::cout << " " << u;
        std::cout << std::endl;
        std::fflush(stdout);
        int res;
        std::cin >> res;
        if (q.size() & 1) {
            return res != x;
        } else {
            return res != 0;
        }
    };

    std::cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 11; j++) {
            if (1 << j & i) p[j].push_back(i);
        }
    }

    for (int i = 0; (1 << i) <= n; i++) {
        if (p[i].size() && query(p[i])) {
            k = i;
            ab |= 1 << i;
        }
    }

    int l = 0, r = p[k].size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        t.clear();
        for (int i = l; i <= mid; i++) t.push_back(p[k][i]);
        if (query(t)) r = mid;
        else l = mid + 1;
    }

    a = p[k][l];
    b = a ^ ab;
    if (a > b) std::swap(a, b);
    std::cout << "! " << a << " " << b << std::endl;

    return 0;
}
