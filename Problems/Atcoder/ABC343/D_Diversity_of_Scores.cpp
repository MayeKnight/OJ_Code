#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> vec(n); // 记录值
    map<ll, int> mp; // 统计值的个数
    mp[0] = n; // 初始情况
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        a--;

        // 去掉原来的值
        if (--mp[vec[a]] == 0) {
            mp.erase(vec[a]);
        }
        // 加入新值
        vec[a] += b;
        mp[vec[a]]++;

        cout << mp.size() << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}