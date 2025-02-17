#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 10, M = N - 10;

struct Node { 
    i64 l, r;
    i64 presum, lastsum, Maxsum;
};

template<class Node>
struct SegmentTree {
    const int n, N;
    std::vector<Node> tr;

    SegmentTree() : n(0) {}
    SegmentTree(int n_) : n(n_), N(n * 4 + 10) {
        tr.reserve(N);
        tr.resize(N);
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u].l = l, tr[u].r = r;
        if (l == r) {
            tr[u] = {l, r, 1, 1, 1};
            return;
        }
        i64 mid = (l + r) >> 1;
        build(u << 1, l, mid); // 左子树
        build(u << 1 | 1, mid + 1, r); // 右子树
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void pushup(Node& U, Node& L, Node& R) {
        U.l = L.l, U.r = R.r;

        if (L.presum == L.r - L.l + 1) {
            U.presum = L.presum + R.presum;
        } else {
            U.presum = L.presum;
        }

        if (R.lastsum == R.r - R.l + 1) {
            U.lastsum = L.lastsum + R.lastsum;
        } else {
            U.lastsum = R.lastsum;
        }

        U.Maxsum = std::max({L.Maxsum, R.Maxsum, L.lastsum + R.presum});
    }

    void modify(int u, int pos) {
        if (tr[u].l >= pos && tr[u].r <= pos) {
            tr[u].Maxsum ^= 1;
            tr[u].presum = tr[u].lastsum = tr[u].Maxsum;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (pos <= mid)
            modify(u << 1, pos); // 左子树
        else
            modify(u << 1 | 1, pos); // 右子树
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    int query(int u, int k) {
        if (tr[u].l == tr[u].r)
            return tr[u].l;
        if (tr[u << 1].Maxsum >= k)
            return query(u << 1, k);

        if (tr[u << 1].lastsum + tr[u << 1 | 1].presum >= k) {
            return tr[u << 1].r - tr[u << 1].lastsum + 1;
        }

        return query(u << 1 | 1, k);
    }
};

SegmentTree<Node> tr(M);

void solve() {
    std::set<int> s;

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
        tr.modify(1, x);
    }

    int m;
    std::cin >> m;
    while (m--) {
        char op;
        int x;
        std::cin >> op >> x;
        if (op == '+') {
            s.insert(x);
            tr.modify(1, x);
        } else if (op == '-') {
            s.erase(x);
            tr.modify(1, x);
        } else {
            if (x > tr.tr[1].Maxsum) {
                std::cout << M - tr.tr[1].lastsum + 1 << ' ';
            } else {
                std::cout << tr.query(1, x) << ' ';
            }
        }
    }

    std::cout << '\n';

    for (auto& x : s) {
        tr.modify(1, x);
    }
}

int main() {
#ifdef qmwneb   
    freopen(".in.txt", "r", stdin);
    freopen(".out.txt", "w", stdout);
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
