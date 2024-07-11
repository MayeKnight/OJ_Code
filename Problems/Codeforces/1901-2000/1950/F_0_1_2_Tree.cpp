#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c != a + 1) {
        cout << "-1\n";
        return;
    }

    queue<int> q;
    q.emplace(0);
    int ans = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        ans = x;
        if (a) {
            a--;
            q.emplace(x + 1);
            q.emplace(x + 1);
        } else if (b) {
            b--;
            q.emplace(x + 1);
        }
    }

    cout << ans << "\n";
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
