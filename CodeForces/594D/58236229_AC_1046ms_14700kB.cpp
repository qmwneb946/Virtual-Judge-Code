#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 5, M = 1e6 + 5;
const int mod = 1e9 + 7;
int n, m, tot, a[N], b[N], p[M / 10], f[M], pre[N], lst[M], ans[N];
bool flg[M];

struct Data {
    int l, r, id;
    bool operator < (const Data &rhs) const {
        return r < rhs.r;
    }
} q[N];

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!flg[i]) p[++tot] = i, f[i] = i;
        for (int j = 1; j <= tot && i * p[j] <= n; ++j) {
            flg[i * p[j]] = 1;
            f[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int pow(int x, int p) {
    int ret = 1;
    for (; p; p >>= 1, x = 1LL * x * x % mod) 
        if (p & 1) ret = 1LL * ret * x % mod;
    return ret;
}

int inv(int x) {
    return pow(x, mod - 2);
}

void add(int x, int val) {
    for (; x <= n; x += x & -x) b[x] = 1LL * b[x] * val % mod;
}

int query(int x) {
    int ret = 1;
    for (; x; x ^= x & -x) ret = 1LL * ret * b[x] % mod;
    return ret;
}

void update(int i) {
    for (int x = a[i], p = f[x]; x > 1; p = f[x]) {
        add(i, p - 1);
        add(i, inv(p));
        if (lst[p]) add(lst[p], inv(p - 1)), add(lst[p], p);
        lst[p] = i;
        while (x % p == 0) x /= p;
    }
}

int main() {
    sieve(M - 5);
    scanf("%d", &n);
    pre[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pre[i] = 1LL * pre[i - 1] * a[i] % mod;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    std::sort(q + 1, q + m + 1);
    for (int i = 0; i <= n; ++i) b[i] = 1;
    for (int i = 1, j = 0; i <= m; ++i) {
        int x = q[i].l, y = q[i].r;
        while (j < y) update(++j);
        ans[q[i].id] = 1LL * pre[y] * inv(pre[x - 1]) % mod * query(y) % mod * inv(query(x - 1)) % mod;
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}
