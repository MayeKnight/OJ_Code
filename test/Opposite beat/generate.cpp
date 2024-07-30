#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25);
    uniform_int_distribution<> n(1, 200);

    const string path("test/Opposite beat/_in.txt");
    fstream io(path);
    if (!io.is_open()) {
        cerr << "Failed" << endl;
    }

    cout << "Start!" << endl;
    io << 100 << endl;
    for (int k = 0; k < 100; ++k) {
        string s(n(gen), ' ');
        io << s.size() << endl;
        for (int i = 0; i < s.size(); ++i) {
            s[i] = 'a' + dis(gen);
        }
        io << s << endl;
    }
    cout << "End!" << endl;
}

int main() {
    solve();

    return 0;
}