#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, n;
    std::cin >> T;
    
    while (T--) {
        std::cin >> n;
        std::vector<int> a(n + 1), id(n + 1);
        std::set<int> s1, s2;
        i64 sum = 0;
        
        // 读入数据
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        
        // 计算初始的 sum
        for (int i = 2; i <= n; i++) {
            sum += 1LL * (i - 1) * (n - i + 1);
        }
        
        // 初始化集合
        for (int i = 0; i <= n + 1; i++) s1.emplace(i);
        s2.emplace(0);
        s2.emplace(n + 1);
        
        // 对 id 数组进行排序
        for (int i = 1; i <= n; i++) id[i] = i;
        std::sort(id.begin() + 1, id.end(), [&](int i, int j) { return a[i] < a[j]; });
        
        // 执行更新
        for (int i = 1; i <= n; i++) {
            int b = id[i];
            int left = *(--s1.lower_bound(b));
            int right = *s1.upper_bound(b);
            if (right != n + 1) {
                int up = *s2.lower_bound(right);
                sum -= 1LL * (b - left) * (up - right);
            }
            s1.erase(b);
            s2.emplace(b);
        }
        
        // 输出结果
        std::cout << sum << '\n';
    }

    return 0;
}
