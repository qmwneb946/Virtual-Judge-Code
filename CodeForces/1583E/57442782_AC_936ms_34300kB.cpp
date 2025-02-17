#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 3e5 + 5;

int n, m, q, cnt, vis[N], fl[N], a[N], b[N];
vector<int> e[N], f[N], cur, ans;

void dfs(int id) {
    vis[id] = 1;
    for (int it : e[id]) {
        if (vis[it]) continue;
        f[id].push_back(it);
        f[it].push_back(id);
        dfs(it);
    }
}

void dfs2(int id, int fa, int aim) {
    cur.push_back(id);
    if (id == aim) {
        ans = cur;
        return;
    }
    for (int it : f[id]) {
        if (it == fa) continue;
        dfs2(it, id, aim);
    }
    cur.pop_back();
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i] >> b[i];
        fl[a[i]] ^= 1;
        fl[b[i]] ^= 1;
    }

    for (int i = 1; i <= n; i++) cnt += fl[i];
    if (cnt == 0) {
        cout << "YES\n";
        for (int i = 1; i <= q; i++) {
            cur.clear();
            dfs2(a[i], 0, b[i]);
            cout << ans.size() << endl;
            for (int it : ans) {
                cout << it << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO\n" << cnt / 2 << endl;
    }

    return 0;
}
