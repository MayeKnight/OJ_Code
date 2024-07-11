#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;
    int a[n];
    int minV = 1e9 + 1, maxV = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxV = max(maxV, a[i]);
        minV = min(minV, a[i]);
    }
    cout << maxV - minV << "\n";
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
