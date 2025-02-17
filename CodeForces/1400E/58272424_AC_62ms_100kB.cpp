#include <bits/stdc++.h>

using i64 = long long;

constexpr int maxn = 5010;
constexpr int inf = 0x3f3f3f3f;
int a[maxn];

int solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return std::min(a[l], 1);
    int minn = inf, tmp;
    for (int i = l; i <= r; i++) {
        if (minn > a[i]) {
            minn = a[i];
            tmp = i;
        }
    }
    for (int i = l; i <= r; i++) a[i] -= minn;
    return std::min(r - l + 1, solve(l, tmp - 1) + solve(tmp + 1, r) + minn);
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    std::cout << solve(1, n) << "\n";
    
    return 0;
}
