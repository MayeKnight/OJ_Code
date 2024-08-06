#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

int Ask(int a, int b) {
    cout << format("? {} {}", a, b) << endl;
    int val;
    cin >> val;
    return val;
}
void Ans(int a) {
    cout << format("! {}", a) << endl;
}

void solve() {
    int l = 1, r = 999;
    while (l + 1 < r) {
        if (l + 2 < r) {
            int x = (2 * l + r) / 3, y = (l + 2 * r) / 3;
            int v = Ask(x, y);
            if (v == x * y) {
                l = y;
            } else if (v == x * (y + 1)) {
                l = x;
                r = y;
            } else {
                r = x;
            }
        } else {
            int mid = (l + r) >> 1;
            if (Ask(1, mid) == mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }
    Ans(r);
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