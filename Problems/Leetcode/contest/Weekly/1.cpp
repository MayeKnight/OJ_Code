#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j <= n; ++j) {
                string tmp = s.substr(i, j);
                if (count(tmp.begin(), tmp.end(), '0') <= k || count(tmp.begin(), tmp.end(), '1') <= k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    return 0;
}