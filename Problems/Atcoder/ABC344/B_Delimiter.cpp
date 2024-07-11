#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    vector<int> vec;
    int t;
    while (cin >> t) {
        vec.emplace_back(t);
    }

    for (int i = vec.size() - 1; i >= 0; --i) {
        cout << vec[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
