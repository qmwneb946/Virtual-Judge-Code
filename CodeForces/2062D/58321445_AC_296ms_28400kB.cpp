#include <bits/stdc++.h>

using i64 = long long;

int t, n, x, y, tot;
int l[200005], r[200005], f[200005], a[200005];
std::vector<int> edge[200005];

void add(int x, int y) {
    edge[x].push_back(y);
    edge[y].push_back(x);
}

void dfs(int x, int fa) {
    f[x] = fa;
    bool flag = true;
    for (int y : edge[x]) {
        if (y == fa) continue;
        dfs(y, x);
        a[x] = std::max(a[x], std::max(l[x], a[y]));
        flag = false;
    }
    if (flag) a[x] = l[x];
    a[x] = std::min(a[x], r[x]);
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> l[i] >> r[i];
        }
        for (int i = 1; i < n; i++) {
            std::cin >> x >> y;
            add(x, y);
        }

        std::fill(a, a + n + 1, 0);
        std::fill(f, f + n + 1, 0);
        
        dfs(1, 0);

        i64 maxn = 0;
        for (int i = 1; i <= n; i++) {
            maxn += std::max(0ll, static_cast<i64>(a[i]) - a[f[i]]);
        }

        std::cout << maxn << '\n';

        // 清理图的邻接表
        for (int i = 1; i <= n; i++) {
            edge[i].clear();
        }
    }

    return 0;
}
