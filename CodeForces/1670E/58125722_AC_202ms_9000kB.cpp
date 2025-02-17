#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

int T, p, n, U[N], V[N], dres[N], eres[N], cnt;
std::vector<int> edge[N];

void dfs(int u, int fa) {
    for (int i = 0; i < edge[u].size(); i++) {
        int vid = edge[u][i], v = 0;
        if (U[vid] == u)
            v = V[vid];
        else
            v = U[vid];

        if (v == fa) continue;

        if ((dres[u] >> p) & 1) {
            dres[v] = ++cnt;
            eres[vid] = cnt + (1 << p);
        } else {
            ++cnt;
            dres[v] = cnt + (1 << p);
            eres[vid] = cnt;
        }

        dfs(v, u);
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     assert(freopen(".in.txt", "r", stdin));
    //     assert(freopen(".out.txt", "w", stdout));
    // #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;

    while (T--) {
        std::cin >> p;
        n = (1 << p);
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            U[i] = V[i] = dres[i] = eres[i] = 0;
            edge[i].clear();
        }

        for (int i = 1; i < n; i++) {
            std::cin >> U[i] >> V[i];
            edge[U[i]].push_back(i);
            edge[V[i]].push_back(i);
        }

        dres[1] = (1 << p);
        dfs(1, 0);

        std::cout << 1 << "\n";

        for (int i = 1; i <= n; i++) std::cout << dres[i] << " ";
        std::cout << "\n";

        for (int i = 1; i < n; i++) std::cout << eres[i] << " ";
        std::cout << "\n";
    }

    return 0;
}
