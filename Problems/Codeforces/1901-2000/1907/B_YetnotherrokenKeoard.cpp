#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    string ss(s);
    vector<int> lower, upper;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'b') {
            if (!lower.empty()) {
                lower.pop_back();
            }
            continue;
        }
        if (s[i] == 'B') {
            if (!upper.empty()) {
                upper.pop_back();
            }
            continue;
        }

        if (islower(ss[i])) {
            lower.emplace_back(i);
        } else {
            upper.emplace_back(i);
        }
    }

    vector<int> vec;
    vec.insert(vec.begin(), lower.begin(), lower.end());
    vec.insert(vec.begin(), upper.begin(), upper.end());
    ranges::sort(vec);
    for (int& v : vec) {
        cout << ss[v];
    }
    cout << "\n";
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
