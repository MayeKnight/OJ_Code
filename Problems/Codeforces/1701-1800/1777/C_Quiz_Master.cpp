#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    constexpr int N = 1e5 + 1;
    vector<vector<int>> factors(N); // 约数
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            factors[j].emplace_back(i);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& v : a) {
            cin >> v;
        }

        ranges::sort(a);
        a.erase(unique(a.begin(), a.end()), a.end());

        // 滑窗
        int ans = INT_MAX;
        int p = 0, res = m;
        vector<int> cnt(m + 1);
        for (int& v : a) {
            for (int& fac : factors[v]) {
                if (fac > m) {
                    break;
                }

                // fill
                if (cnt[fac] == 0) {
                    res--;
                }
                cnt[fac]++;
            }

            // move the left pointer
            while (res == 0) {
                ans = min(ans, v - a[p]); // update

                for (int& d : factors[a[p]]) {
                    if (d > m) {
                        break;
                    }

                    cnt[d]--;
                    res += cnt[d] == 0;
                }
                p++;
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }

    return 0;
}
