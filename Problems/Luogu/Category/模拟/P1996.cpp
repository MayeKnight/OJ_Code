#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1);
    int s = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            if (++s > n) {
                s = 1;
            }
            if (vis[s]) {
                i--;
            }
        }
        cout << s << " ";
        vis[s] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
