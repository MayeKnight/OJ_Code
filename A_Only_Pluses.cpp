#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int mx = a * b * c;
    for (int i = 0; i <= 5; ++i) {
        for (int j = 0; j <= 5 - i; ++j) {
            int k = 5 - i - j;
            if (k < 0) {
                continue;
            }
            mx = max(mx, (a + i) * (b + j) * (c + k));
        }
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}