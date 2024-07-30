#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const string in_path = "test/Opposite beat/_in.txt";
const string out_path = "test/Opposite beat/_out.txt";
const string out2_path = "test/Opposite beat/_out2.txt";

auto check = [](fstream& io) {
    if (!io.is_open()) {
        cerr << "Failed to open file" << endl;
    }
};

void solve(fstream& cin, fstream& cout) {}

void solve2(fstream& cin, fstream& cout) {}

void exec() {
    fstream in(in_path), in2(in_path);
    fstream out(out_path, std::ios::out | std::ios::trunc), out2(out2_path, std::ios::out | std::ios::trunc);
    check(in), check(in2), check(out), check(out2);

    int T1 = 1, T2 = 1;
    in >> T1, in2 >> T2;
    while (T1--) {
        solve(in, out);
    }
    while (T2--) {
        solve2(in2, out2);
    }

    in.close(), in2.close(), out.close(), out2.close();
}

void diff() {
    fstream out(out_path), out2(out2_path);
    check(out), check(out2);

    string s1, s2;
    int lineNum = 1;
    while (getline(out, s1) && getline(out2, s2)) {
        if (s1 != s2) {
            cerr << "Difference at line " << lineNum << ": \n    " << s1 << "  ---------  " << s2 << "\n" << endl;
        }
        lineNum++;
    }

    out.close(), out2.close();
    cout << "Completed successfully." << endl;
}

int main() {
    exec();
    diff();

    return 0;
}