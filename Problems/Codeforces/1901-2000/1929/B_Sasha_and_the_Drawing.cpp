#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n, k;
    cin >> n >> k;

    cout << (k + (k > 4 * n - 3) + 1) / 2 << "\n";
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
