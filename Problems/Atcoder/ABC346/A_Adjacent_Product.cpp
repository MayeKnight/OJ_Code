#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << vec[i] * vec[i + 1] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
