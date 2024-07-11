#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int w, b;
    cin >> w >> b;
    string s("wbwbwwbwbwbw");
    s += s;

    int cnt = min(w / 7, b / 5);
    w -= cnt * 7;
    b -= cnt * 5;

    int cntw = 0, cntb = 0;
    for (int l = 0, r = 0; r < s.size();) {
        while (r - l < w + b) {
            (s[r++] == 'w' ? cntw : cntb)++;
        }
        if (cntw == w && cntb == b) {
            cout << "Yes\n";
            return;
        }

        (s[l++] == 'w' ? cntw : cntb)--;
    }

    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
