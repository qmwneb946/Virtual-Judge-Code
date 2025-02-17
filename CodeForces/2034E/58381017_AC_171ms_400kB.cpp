#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n == 1 && k == 1) return std::cout << "Yes" << std::endl << "1" << std::endl, void();
    if (n == 1 || k == 1) return std::cout << "No" << std::endl, void();
    if (k % 2 == 0) {
        std::vector<std::vector<int>> ans;
        std::vector<int> L(n, 0), R(n, 0);
        for (int i = 0; i < n; i++) L[i] = i + 1;
        for (int i = 0; i < n; i++) R[i] = n - i;
        do {
            ans.push_back(L);
            ans.push_back(R);
            std::next_permutation(L.begin(), L.end());
            std::prev_permutation(R.begin(), R.end());
        } while (L < R && ans.size() < k);
        if (ans.size() < k) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
            for (std::vector<int> v : ans) {
                for (int i : v) {
                    std::cout << i << ' ';
                }
                std::cout << std::endl;
            }
        }
        return;
    }
    if (n % 2 == 0) {
        std::cout << "No\n";
        return;
    }
    std::vector<std::vector<int>> ans(3, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        ans[0][i] = i + 1;
        ans[1][i] = (i + n / 2) % n + 1;
        ans[2][i] = 3 * (n + 1) / 2 - ans[0][i] - ans[1][i];
    }
    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) L[i] = i + 1, R[i] = n - i;
    do {
        if (ans[0] != L && ans[0] != R && ans[1] != L && ans[1] != R && ans[2] != L && ans[2] != R) ans.push_back(L), ans.push_back(R);
        next_permutation(L.begin(), L.end());
        prev_permutation(R.begin(), R.end());
    } while (L < R && ans.size() < k);
    if (ans.size() < k) {
        std::cout << "No\n";
    }
    else {
        std::cout << "Yes\n";
        for (std::vector<int> v : ans) {
            for (int i : v) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
        }
    }
    return;
}

int main() {
#ifdef qmwneb
    freopen(".in.txt", "r", stdin);
    freopen(".out.txt", "w", stdout);
#endif
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}