#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 s, n, k; 
    std::cin >> s >> n >> k;
    i64 tt = 2 * k * (n / k) + n % k;
    
    if (s == k) {
        std::cout << "YES" << std::endl; 
        return; 
    }
    
    if (s >= tt) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
