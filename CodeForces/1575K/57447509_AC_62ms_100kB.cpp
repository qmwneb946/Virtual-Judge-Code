#include<iostream>
constexpr long long mod = 1e9 + 7;
long long n, m, k, r, c, ax, ay, bx, by;

long long ksm(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    std::cin >> n >> m >> k >> r >> c;
    std::cin >> ax >> ay >> bx >> by;
    if (ax == bx && ay == by) {
        std::cout << ksm(k, n * m) % mod << "\n";
    } else {
        std::cout << ksm(k, n * m - r * c) % mod << "\n";
    }
    return 0;
}
