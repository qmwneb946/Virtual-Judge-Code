#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 mod = 998244353;


int n, ans;
std::vector <int> arr;    
std::vector <bool> vis;


void dfs (int x, int &cnt) {
    cnt++;
    vis[x] = true;
    for (int i = 0; i < n; i++) {
        if ((arr[x] & arr[i]) && (!vis[i])) {
            dfs (i, cnt);
        }
    }
}

bool check () {
    vis.assign(n, 0);
    int cnt = 0;
    dfs (0, cnt);
    return cnt == n;
}

int lowbit (int x) { return x & (-x); }

void solve() { 
    std::cin >> n; ans = 0;
    arr.assign(n, 0);
    for (int &i : arr) std::cin >> i;
    for (int &i : arr) if (i == 0) i++, ans++;
    if (check()) {
        std::cout << ans + 0 << '\n';
        for (int i = 0; i < n; i++) std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int &j : arr) {
        j--;
        if (check()) {
            std::cout << ans + 1 << '\n';
            for (int i = 0; i < n; i++) std::cout << arr[i] << ' ';
            std::cout << '\n';
            return;
        }
        j += 2;
        if (check()) {
            std::cout << ans + 1 << '\n';
            for (int i = 0; i < n; i++) std::cout << arr[i] << ' ';
            std::cout << '\n';
            return;
        }
        j--;
    }

    int max_lowbit = 0;

    for (int i : arr) max_lowbit = std::max(max_lowbit, lowbit(i));

    for (int &i : arr) {
        if (lowbit(i) == max_lowbit) {
            i--;
            break;
        }
    }
    for (int &i : arr) {
        if (lowbit(i) == max_lowbit) {
            i++;
            break;
        }
    }
    std::cout << ans + 2 << '\n';
    for (int i = 0; i < n; i++) std::cout << arr[i] << ' ';
    std::cout << '\n';
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
