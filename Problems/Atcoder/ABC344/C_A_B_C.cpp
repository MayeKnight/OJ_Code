#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int& v : v1) {
        cin >> v;
    }

    int m;
    cin >> m;
    vector<int> v2(m);
    for (int& v : v2) {
        cin >> v;
    }
    
    int l;
    cin >> l;
    vector<int> v3(l);
    for (int& v : v3) {
        cin >> v;
    }

    unordered_map<int, int> ump;
    for (int& n1 : v1) {
        for (int& n2 : v2) {
            for (int& n3 : v3) {
                ump[n1 + n2 + n3]++;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << (ump[num] > 0 ? "Yes" : "No") << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
