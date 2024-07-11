#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k, s1, s2;
    cin >> n >> k >> s1 >> s2;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }

    auto func = [&](int s) {
        ll ans = a[s] * 1ll * k;
        ll res = 0;
        for (int i = 1; i <= min(n, k); ++i) {
            res += a[s];
            s = p[s];
            ans = max(ans, res + a[s] * 1ll * (k - i));
        }
        return ans;
    };

    ll ans1 = func(s1), ans2 = func(s2);
    cout << (ans1 > ans2 ? "Bodya" : ans1 < ans2 ? "Sasha" : "Draw") << "\n";
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
