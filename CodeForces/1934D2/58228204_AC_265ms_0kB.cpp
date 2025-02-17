#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
using i64 = long long;
const int N = 5e5 + 5;
int T;
i64 n, p1, p2;

void los() {
    std::cin >> n;
    auto ck = [&](i64 x) { return __builtin_popcountll(x) & 1; };
    auto lb = [&](i64 x) { return 1ll << (63 - __builtin_clzll(x)); };

    std::cout << (ck(n) ? "Second" : "First") << std::endl;
    if (!ck(n)) std::cout << lb(n) << " " << (n ^ lb(n)) << std::endl;
    
    while (true) {
        std::cin >> p1 >> p2;
        if (p1 == -1) assert(0);
        if (!p1 && !p2) return;
        
        if (ck(p1)) 
            std::cout << lb(p2) << " " << (p2 ^ lb(p2)) << std::endl;
        else 
            std::cout << lb(p1) << " " << (p1 ^ lb(p1)) << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (std::cin >> T; T--;) los();
    
    return 0;
}
