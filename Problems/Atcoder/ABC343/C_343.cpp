#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    ll l = 0, r = 1e6 + 1;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;

        (mid * mid * mid > n ? r : l) = mid;
    }
    while (l * l * l >= 0) {
        string s = to_string(l * l * l);
        string t(s);
        reverse(t.begin(), t.end());
        if (s == t) {
            cout << s << "\n";
            return;
        }

        l--;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
