#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++) {
    //     string s = "";
    //     for (int j = 0; j < n; j++) {
    //         s += ((i + j) % 2 == 0 ? "##" : "..");
    //     }
    //     cout << s << '\n';
    //     cout << s << '\n';
    // }

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            cout << "#."[(i >> 1) ^ (j >> 1) & 1];
        }
        cout << "\n";
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
