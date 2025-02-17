#include <bits/stdc++.h>
using namespace std;

const int N = 256;
int n, idx[N], cnt[N], vis[N];

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cout << "? " << i << " ";
        for (int j = 1;j <= n;j++) cout << (j != i);
        cout << endl;
        cin >> cnt[idx[i] = i];
    }
    sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {return cnt[x] < cnt[y];});
    int sum = 0;
    for (int i = n;i >= 1;i--) {
        sum += cnt[idx[i]];
        vis[idx[i]] = 1;
        if (sum - (n - i + 1) * (n - i) / 2 == (i - 1) * (n - i + 1)) break;
    }
    cout << "! ";
    for (int i = 1;i <= n;i++) cout << vis[i];
    cout << endl;
    return 0;
}