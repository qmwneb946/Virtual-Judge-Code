#include <bits/stdc++.h>

#define int long long

signed main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);  
    int T;
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::vector<int> A(N), B(N), g(N);
        int s = 0;

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i] >> B[i];
            g[i] = std::max(M - B[i], 0ll);
            s += A[i] - B[i] + M - 2 * g[i];
        }

        for (int i = 0; i < N; ++i) {
            int t = std::min({std::max(s, 0ll) / 2, M - g[i], A[i] - g[i]});
            g[i] += t;
            s -= t * 2;
        }

        std::cout << std::abs(s) << "\n";
        for (int i = 0; i < N; ++i) {
            std::cout << g[i] << " " << M - g[i] << "\n";
        }
    }

    return 0;
}
