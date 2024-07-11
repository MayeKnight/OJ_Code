#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

/*
    逆序数
*/
void solve() {
    string s;
    cin >> s;

    ll ans = 0;
    int cnt = 0;
    for (char ch : s) {
        if (ch == '1') {
            cnt++;
        } else {
            if (cnt > 0) {
                ans += cnt + 1;
            }
        }
    }

    // int id = ranges::find(s, '1') - s.begin();
    // for (int i = id, pre = id; i < s.size(); ++i) {
    //     if (s[i] == '0') {
    //         ans += i - pre + 1;
    //         pre++;
    //     }
    // }
    cout << ans << "\n";
}

void Mysolve() {
    string s;
    cin >> s;

    ll ans = 0;

    cout << ans << "\n";
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
