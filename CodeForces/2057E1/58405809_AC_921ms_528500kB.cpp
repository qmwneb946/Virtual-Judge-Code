#include <bits/stdc++.h>

using i64 = long long;

void solve () {
  struct E {int x, y, z; };
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector <E> e(m, {0, 0, 0});
  std::vector <int> fa(n + 1, 0), len(n + 1, 0);
  std::vector dis(n + 1, std::vector <std::vector <i64>>(n + 1, std::vector <i64> (n + 1, 1e9)));
  auto find = [&](auto self, int x) {
    if (fa[x] == x) return x;
    else return fa[x] = self (self, fa[x]);
  };
  for (int i = 1; i <= n; i++) dis[0][i][i] = 0;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    std::cin >> e[i].x >> e[i].y >> e[i].z;
    dis[0][e[i].x][e[i].y] = dis[0][e[i].y][e[i].x] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[0][i][j] = std::min(dis[0][i][j], dis[0][i][k] + dis[0][k][j]);
      }
    }
  }
  sort (e.begin(), e.end(), [](E a, E b) {return a.z < b.z; });
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int fx = find(find, e[i].x), fy = find(find, e[i].y);
    if (fx == fy) continue;
    cnt++;
    len[cnt] = e[i].z, fa[fx] = fy;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        dis[cnt][x][y] = std::min ({ dis[cnt - 1][x][y], dis[cnt - 1][x][e[i].x] + dis[cnt - 1][y][e[i].y], dis[cnt - 1][x][e[i].y] + dis[cnt - 1][y][e[i].x] } );
      }
    }
  }
  while (q--) {
    int a, b, k;
    std::cin >> a >> b >> k;
    int l = 1, r = cnt, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (dis[mid][a][b] < k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << len[ans] << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
}