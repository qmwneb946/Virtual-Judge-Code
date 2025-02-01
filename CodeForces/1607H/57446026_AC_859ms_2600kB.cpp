#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 200005;

struct Node {
    int x, y, m, id, s, l, r;
};

// 比较函数用于排序，按 s, r, l 依次排序
bool cmp(const Node& a, const Node& b) {
    if (a.s != b.s) return a.s < b.s;
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}

// 比较函数按 id 排序
bool cmpById(const Node& a, const Node& b) {
    return a.id < b.id;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Node> nodes(n);
    std::vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> nodes[i].x >> nodes[i].y >> nodes[i].m;
        nodes[i].id = i;
        nodes[i].s = nodes[i].x + nodes[i].y - nodes[i].m;
        nodes[i].l = std::max(0, nodes[i].x - nodes[i].m);
        nodes[i].r = nodes[i].x - std::max(0, nodes[i].m - nodes[i].y);
    }

    std::sort(nodes.begin(), nodes.end(), cmp);

    int tot = 0;
    for (int l = 0; l < n; ++l) {
        int r = l;
        while (r + 1 < n && nodes[r + 1].s == nodes[l].s) {
            ++r;
        }
        for (int i = l; i <= r; ++i) {
            int j = i;
            while (j + 1 <= r && nodes[j + 1].l <= nodes[i].r) {
                ++j;
                ans[nodes[j].id] = nodes[i].r;
            }
            ans[nodes[i].id] = nodes[i].r;
            ++tot;
            i = j;
        }
        l = r;
    }

    std::sort(nodes.begin(), nodes.end(), cmpById);

    std::cout << tot << "\n";
    for (int i = 0; i < n; ++i) {
        int t = nodes[i].x - ans[i];
        std::cout << t << " " << nodes[i].m - t << "\n";
    }
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
