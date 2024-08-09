#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    vector<int> vec {4, 2, 6, 2, 1};
    int n = vec.size();
    vector<int> pre(n + 1);
    partial_sum(vec.begin(), vec.end(), pre.begin() + 1);

    for (int& v : pre) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}