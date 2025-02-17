#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   private:
    vector<int> tag, mn;
    int n;

    void down(int u) {
        if (tag[u]) {
            int lc = u << 1, rc = u << 1 | 1;
            tag[lc] += tag[u], tag[rc] += tag[u];
            mn[lc] += tag[u], mn[rc] += tag[u];
            tag[u] = 0;
        }
    }

    void up(int u) {
        int lc = u << 1, rc = u << 1 | 1;
        mn[u] = min(mn[lc], mn[rc]);
    }

    void mdf(int u, int l, int r, int L, int R, int v) {
        if (L > R || R < l || r < L)
            return;
        if (L <= l && r <= R) {
            tag[u] += v, mn[u] += v;
            return;
        }
        down(u);
        int mid = (l + r) >> 1;
        mdf(u << 1, l, mid, L, R, v), mdf(u << 1 | 1, mid + 1, r, L, R, v);
        up(u);
    }

    int qry(int u, int l, int r, int L, int R) {
        if (R < l || r < L)
            return INT_MAX;
        if (L <= l && r <= R)
            return mn[u];
        down(u);
        int mid = (l + r) >> 1;
        return min(qry(u << 1, l, mid, L, R), qry(u << 1 | 1, mid + 1, r, L, R));
    }

   public:
    SegmentTree(int size) : n(size) {
        tag.resize(4 * n);
        mn.resize(4 * n);
    }

    void build() {
        fill(tag.begin(), tag.end(), 0);
        fill(mn.begin(), mn.end(), 0);
    }

    void modify(int L, int R, int v) {
        mdf(1, 1, n, L, R, v);
    }

    int query(int L, int R) {
        return qry(1, 1, n, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n + 1), p1(n + 1), p2(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p1[i] = p2[i] = 0;
        }
        int l = 1, res = 0;
        SegmentTree segTree(n);
        segTree.build();
        for (int i = 1; i <= n; i++) {
            segTree.modify(p2[a[i]] + 1, p1[a[i]], -1);
            segTree.modify(p1[a[i]] + 1, i, 1);
            p2[a[i]] = p1[a[i]], p1[a[i]] = i;
            if (!segTree.query(l, i)) {
                l = i + 1, res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
