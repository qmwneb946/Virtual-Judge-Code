#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 6e5 + 5;
int n, d, c[51];
int last_maxn, maxn;
bool f[N];

int find(int l, int r) {
    for (int i = r; i >= l; i--)
        if (f[i]) return i;
    return l;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = N - 1; j >= c[i]; j--)
            if (f[j - c[i]]) f[j] = 1;
    
    for (int i = 1;; i++) {
        last_maxn = maxn;
        maxn = find(maxn, d + last_maxn);
        if (last_maxn != maxn) continue;
        std::cout << maxn << " " << i - 1 << "\n";
        return 0;
    }
}
