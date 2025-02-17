#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> mp, f; // 状态压缩； 记忆化
int SG(int x) {
    if (!x) return 0; // 什么都没有就什么都不用干
    if (f.count(x)) return f[x]; // 记忆化
    set<int> st; // mex
    int t = 0, p = x;
    while (p) p >>= 1, t++; // 最高位（因为要保证有一个数能被除）
    for (int i = 1; i <= t; i++) 
        st.insert(
            SG((x >> i) |  // 前半部分是被除以的，所以左移；
            (x & ((1 << (i - 1)) - 1))) // 后半部分是只留取后 [1, i - 1] 位的
        ); 
    int now = 0;
    while (st.count(now)) now++; // 求 mex
    return f[x] = now; // 记忆化
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0)
                    cnt++, x /= j;
                mp[j] |= (1 << (cnt - 1));
            }
        }
        if (x > 1)
            mp[x] |= 1;
    }
    int res = 0; // 异或和
    for (auto i : mp)
        res ^= SG(i.second); // 对于每一个子问题 (每一个质数)求解 SG
    if (res)
        cout << "Mojtaba" << endl;
    else
        cout << "Arpa" << endl;
}