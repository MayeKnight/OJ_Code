#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    set<int> set;
    // unordered_map<int, int> ump;
    for (int& v : vec) {
        cin >> v;

        if (v <= k) {
            set.emplace(v);
            // ump[v]++;
        }
    }

    ll total = (k + 1) * 1LL * k / 2;
    ll sum = accumulate(set.begin(), set.end(), 0ll);
    // ll sum = 0;
    // for (auto iter = ump.begin(); iter != ump.end(); ++iter) {
    //     sum += iter->first;
    // }

    cout << total - sum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
