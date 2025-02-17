#include <bits/stdc++.h>

using i64 = long long;

i64 n, k;
std::string s;
i64 l[100005], r[100005];

void init() {
    l[1] = 1, r[n] = n;
    for (i64 i = 2; i <= n; ++i) l[i] = (s[i] == s[i - 1] ? l[i - 1] : i);
    for (i64 i = n - 1; i; --i) r[i] = s[i] == s[i + 1] ? r[i + 1] : i;
}

bool ch1() {
    if (n == k || l[n - k] == 1 || r[k + 1] == n) return 1;
    for (i64 i = 2; i <= n - k; ++i)
        if (s[i - 1] == s[i + k] && l[i - 1] == 1 && r[i + k] == n) return 1;
    return 0;
}

bool ch2() {
    if (k * 2 < n) return 0;
    for (i64 i = 2; i <= n - k; ++i) {
        if (l[i - 1] != 1 || r[i + k] != n) return 0;
    }
    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    std::cin >> s;
    s = " " + s;
    init();
    if (ch1()) return std::puts("tokitsukaze"), 0;
    if (ch2()) return std::puts("quailty"), 0;
    std::puts("once again");
    return 0;
}