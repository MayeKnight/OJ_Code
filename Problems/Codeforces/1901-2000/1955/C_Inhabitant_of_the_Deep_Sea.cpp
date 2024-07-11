#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ll left = (k + 1) / 2, right = k / 2;
    int l = 0, r = n - 1;
    for (; l < n; ++l) {
        if (left >= vec[l]) {
            left -= vec[l];
        } else {
            break;
        }
    }
    for (; r > l; --r) {
        if (right >= vec[r]) {
            right -= vec[r];
        } else {
            break;
        }
    }
    cout << (l < r ? l + n - 1 - r : (l == r && left + right < vec[l] ? n - 1 : n)) << "\n";

    /*
        int ans = 0;
        int p1 = 0, p2 = n - 1;
        while (k > 0 && p1 < p2) {
            int minV = min(vec[p1], vec[p2]);
            if (k < minV * 2 - 1) { // 对 ans 没有贡献
                break;
            }

            // 左边小
            if (vec[p1] < vec[p2]) {
                // 左边清空，右边减少
                k -= vec[p1] * 2 - 1;
                vec[p2] -= vec[p1] - 1;
                p1++, ans++;

                // 看右边能不能清空
                if (k == 0) {
                    break;
                }
                k -= 1;
                if (--vec[p2] == 0) {
                    p2--, ans++;
                }
            }
            // 右边小
            else if (vec[p1] > vec[p2]) {
                k -= vec[p2] * 2 - 1;
                vec[p1] -= vec[p2];

                // 看右边能不能清空
                if (k == 0) {
                    break;
                }
                k--, p2--, ans++;
            }
            // 一样大
            else {
                if (k >= vec[p1] * 2) {
                    k -= vec[p1] * 2;
                    p1++, p2--;
                    ans += 2;
                } else {
                    ans++;
                    break;
                }
            }
        }

        if (p1 == p2 && k >= vec[p1]) {
            ans++;
        }

        cout << ans << "\n";
    */
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