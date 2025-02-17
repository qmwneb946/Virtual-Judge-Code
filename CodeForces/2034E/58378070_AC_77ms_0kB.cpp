#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        if (n == 1)
            cout << "Yes\n1\n";
        else
            cout << "No\n";
        return;
    }
    if (n == 1) {
        cout << "No\n";
        return;
    }
    if (k % 2 == 0) {
        vector<vector<int>> ans;
        ans.reserve(k);
        vector<int> L(n), R(n);
        for (int i = 0; i < n; ++i) L[i] = i + 1, R[i] = n - i;
        do {
            ans.push_back(L);
            ans.push_back(R);
            next_permutation(L.begin(), L.end());
            prev_permutation(R.begin(), R.end());
        } while (L < R && ans.size() < k);
        if (ans.size() < k)
            cout << "No\n";
        else {
            cout << "Yes\n";
            for (auto& v : ans) {
                for (int i = 0; i < n; ++i) cout << v[i] << " \n"[i == n - 1];
            }
        }
    } else {
        if (n % 2 == 0) {
            cout << "No\n";
            return;
        }
        vector<vector<int>> ans(3, vector<int>(n));
        ans.reserve(k);
        for (int i = 0; i < n; ++i) {
            ans[0][i] = i + 1;
            ans[1][i] = (i + n / 2) % n + 1;
            ans[2][i] = 3 * (n + 1) / 2 - ans[0][i] - ans[1][i];
        }
        vector<int> L(n), R(n);
        for (int i = 0; i < n; ++i) L[i] = i + 1, R[i] = n - i;
        do {
            if (ans[0] != L && ans[0] != R && ans[1] != L && ans[1] != R && ans[2] != L && ans[2] != R)
                ans.push_back(L), ans.push_back(R);
            next_permutation(L.begin(), L.end());
            prev_permutation(R.begin(), R.end());
        } while (L < R && ans.size() < k);
        if (ans.size() < k)
            cout << "No\n";
        else {
            cout << "Yes\n";
            for (auto& v : ans) {
                for (int i = 0; i < n; ++i) cout << v[i] << " \n"[i == n - 1];
            }
        }
    }
}

int main() {
    int T = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
