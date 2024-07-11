#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int flag = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|') {
            flag ^= 1;
            continue;
        }
        if (flag) {
            cout << s[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
