#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a / 2 + b / 2 + c / 2 + d / 2 + a * b * c % 2) << "\n";
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
