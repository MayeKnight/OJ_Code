#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    合唱队形：最长递增子序列
*/
void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    vector<int> f0(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[i] > vec[j]) {
                f0[i] = max(f0[i], f0[j] + 1);
            }
        }
    }

    vector<int> f1(n + 2);
    for (int i = n; i > 0; --i) {
        for (int j = n + 1; j > i; --j) {
            if (vec[i] > vec[j]) {
                f1[i] = max(f1[i], f1[j] + 1);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, f0[i] + f1[i] - 1);
    }
    cout << n - mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}