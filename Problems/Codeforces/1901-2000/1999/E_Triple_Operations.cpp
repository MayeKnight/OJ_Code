#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

const vector<int> vec {0, 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

void solve() {
    int l, r;
    cin >> l >> r;

    auto f = [&](int v) {
        int l = 0, r = 13;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (vec[mid] > v) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    };

    ll v1 = f(l), v2 = f(r);

    auto calc = [&](int val) {
        int v = f(val);
        ll res = (val - vec[v] + 1) * v;
        for (int i = 0; i < v; ++i) {
            res += (vec[i + 1] - vec[i]) * 1ll * i;
        }
        return res;
    };

    cout << calc(r) - calc(l) + v1 * 2 << "\n";
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