#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int num = stoi(s.substr(3));
    cout << (num >= 1 && num <= 349 && num != 316 ? "Yes" : "No") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
