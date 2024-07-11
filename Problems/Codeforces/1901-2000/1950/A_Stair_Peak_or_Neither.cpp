#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && b < c) {
        cout << "STAIR\n";
    } else if (a < b && b > c) {
        cout << "PEAK\n";
    } else {
        cout << "NONE\n";
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
