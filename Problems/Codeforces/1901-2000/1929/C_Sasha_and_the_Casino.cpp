#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;

    ll sum = 0;
    for (int i = 0; i <= x; ++i) {
        sum += sum / (k - 1) + 1;
        if (sum > a) {
            puts("NO");
            return;
        }
    }
    puts("YES");
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
