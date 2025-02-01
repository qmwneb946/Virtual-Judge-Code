#include <bits/stdc++.h>

constexpr int MOD = 4;

std::vector<std::vector<int>> cnt(MOD, std::vector<int>(MOD));

long long compute() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        ++cnt[x % MOD][y % MOD];
    }

    long long result = 0;

    for (int i1 = 0; i1 < MOD; ++i1) {
        for (int j1 = 0; j1 < MOD; ++j1) {
            for (int i2 = 0; i2 < MOD; ++i2) {
                for (int j2 = 0; j2 < MOD; ++j2) {
                    for (int i3 = 0; i3 < MOD; ++i3) {
                        for (int j3 = 0; j3 < MOD; ++j3) {
                            auto gcd = [](int x, int y) {
                                return std::__gcd(std::abs(x), std::abs(y));
                            };

                            int perim_mod = (gcd(i1 - i2, j1 - j2) + 
                                             gcd(i2 - i3, j2 - j3) + 
                                             gcd(i3 - i1, j3 - j1)) % MOD;

                            if (perim_mod == 0) {
                                std::vector<std::vector<int>> temp = cnt;
                                long long count = 1;
                                count *= temp[i1][j1]--;
                                count *= temp[i2][j2]--;
                                count *= temp[i3][j3]--;

                                if (count > 0) {
                                    result += count;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result / 6;
}

int main() {
    std::cout << compute() << '\n';
    return 0;
}
