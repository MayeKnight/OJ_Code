#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 100003;

void solve() {
    int M;
    cin >> M;

    int f0 = 1, f1 = 1;
    int n = 1;
    while (f0 != 0 || f1 != 1) {
        n++;

        int f2 = (f0 + f1) % M;
        f0 = f1;
        f1 = f2;
    }
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
