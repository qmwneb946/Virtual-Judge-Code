#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 210;
constexpr int mod = 1e9 + 7;
constexpr int inv = 5e8 + 4;

i64 n, dep[N], f[N][21], dp[N][N], ans;
struct node {
    i64 to, nxt;
} e[N << 1];

i64 cnt, head[N];

inline void read(i64 &x) {
    x = 0;
    int y = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x = x * y;
}

inline void add(int u, int v) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

i64 ksm(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        b >>= 1;
    }
    return ret;
}

void dfs(i64 x, i64 fa) {
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;
    for (int i = 1; i <= 20; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = e[i].nxt) {
        if (e[i].to != fa) dfs(e[i].to, x);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    read(n);
    for (i64 i = 1, x, y; i <= n - 1; i++) {
        read(x), read(y);
        add(x, y);
        add(y, x);
    }
    for (i64 i = 1; i <= n; i++) dp[0][i] = 1;
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv % mod;
        }
    }
    for (i64 i = 1; i <= n; i++) {
        dfs(i, 0);
        for (i64 j = 1; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                int l = lca(j, k);
                ans = (ans + dp[dep[j] - dep[l]][dep[k] - dep[l]]) % mod;
            }
        }
    }
    printf("%lld\n", ans * ksm(n, mod - 2) % mod);
    return 0;
}
