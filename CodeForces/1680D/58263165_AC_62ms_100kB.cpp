#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, k;
    std::cin >> n >> k;
    
    std::vector<i64> a(n + 1), p(n + 1), d(n + 1);
    
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        d[i] = d[i - 1] + (a[i] == 0);
        p[i] = p[i - 1] + a[i];
    }

    if (std::abs(p[n]) > k * d[n]) {
        std::cout << "-1\n";
        return 0;
    }

    i64 max = -1;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            i64 sum = p[r] - p[l - 1], cnt = d[r] - d[l - 1];
            i64 lSum = p[n] - sum, lCnt = d[n] - cnt;
            max = std::max(max, std::min(std::abs(sum + cnt * k), std::abs(lSum - lCnt * k)));
            max = std::max(max, std::min(std::abs(sum - cnt * k), std::abs(lSum + lCnt * k)));
        }
    }

    std::cout << max + 1 << '\n';
    return 0;
}
