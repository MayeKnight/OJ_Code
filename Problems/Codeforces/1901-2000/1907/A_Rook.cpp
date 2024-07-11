#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    char c1;
    int num;
    cin >> c1 >> num;

    for (int i = 0; i < 8; ++i) {
        if (i + 1 != num) {
            cout << c1 << i + 1 << "\n";
        }

        char c2 = 'a' + i;
        if (c1 != c2) {
            cout << c2 << num << "\n";
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
