#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (vec[vec[i]] == i) {
            cout << 2 << "\n";
            return;
        }
    }
    cout << 3 << "\n";
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
