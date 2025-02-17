#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifdef qmwneb	
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int ans = 0, n, m;
        std::cin >> n >> m;
        
        std::vector<std::vector<int>>   a(n + 1, std::vector<int>(m + 1)),
                                        b(n + 1, std::vector<int>(m + 1)),
                                        c(n + 1, std::vector<int>(m + 1)),
                                        d(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) std::cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) std::cin >> b[i][j];

        for (int k = 0; k <= 20; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    c[i][j] = (a[i][j] >> k) & 1;
                    d[i][j] = (b[i][j] >> k) & 1;
                }
            }
            for (int w = 1; w <= 30; w++) {
                int f = 1;
                for (int j = 1; j <= m; j++) {
                    int f = 0;
                    for (int i = 1; i <= n; i++)
                        if (!c[i][j] && d[i][j]) f = 1;
                    if (f)
                        for (int i = 1; i <= n; i++) c[i][j] = 1;
                    for (int i = 1; i <= n; i++)
                        if (c[i][j] != d[i][j])
                            for (int kk = 1; kk <= m; kk++) c[i][kk] = 0;
                }
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        if (c[i][j] != d[i][j]) f = 0;
                if (f) break;
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (c[i][j] != d[i][j]) ans = 1;
            if (ans) break;
        }
        if (ans)
            std::cout << "No\n";
        else
            std::cout << "Yes\n";
    }
    return 0;
}
