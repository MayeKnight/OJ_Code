#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int p = 0;
    for (int i = 0; i < m; ++i) {
        p += a[p] == b[i];
    }
    cout << p << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
