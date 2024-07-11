#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

constexpr int N = 1e5;
vector<int> bin;
vector<int> dp(N);
auto init = [] {
    for (int s = 1; s < (1 << 5); ++s) {
        int v = 0;
        for (int i = 4; i >= 0; --i) {
            v = v * 10 + (s >> i & 1);
        }
        bin.emplace_back(v);
    }
    bin.emplace_back(N);

    dp[1] = 1;
    for (int& v : bin) {
        for (int i = 1; i * v <= N; ++i) {
            dp[i * v] |= dp[i];
        }
    }

    return 0;
}();

void solve() {
    int n;
    std::cin >> n;

    std::cout << (dp[n] ? "YES" : "NO") << "\n";
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

void mysolve() {
    int n;
    cin >> n;

    vector<int> nums = {10, 11, 101, 111, 1001, 10001, 11111, 100001};

    int flag = 0;
    int m = n;
    while (n) {
        int b = n % 10;
        n /= 10;
        if (b != 0 && b != 1) {
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "YES\n";
        return;
    }

    n = m;
    // todo
    for (int i = 6; i >= 0; --i) {
        for (int j = 0; j < 20; ++j) {
            if (n % nums[i] == 0) {
                n /= nums[i];
            }
        }
    }

    while (n) {
        int b = n % 10;
        n /= 10;
        if (b != 0 && b != 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}