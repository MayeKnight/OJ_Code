#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int x, y, t;
    cin >> x >> y >> t;

    if (y < x) { // 先碰到钥匙
        cout << x << "\n";
    } else { // 先碰到宝箱
        if (x + t >= y) { // 可以搬宝箱到钥匙处
            cout << y << "\n";
        } else {
            cout << y * 2 - x - t << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
