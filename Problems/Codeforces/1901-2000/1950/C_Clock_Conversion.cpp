#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int h, m;
    char c;
    cin >> h >> c >> m;

    int hh = (h + 11) % 12 + 1;
    cout << (hh < 10 ? "0" : "") << hh << ":" << (m < 10 ? "0" : "") << m << " " << (h < 12 ? "AM" : "PM") << '\n';
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
