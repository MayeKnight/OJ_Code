#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
1 :  [0, 9, 99, 999, 9999, 99999, 999999, 9999999]
3 :  [0, 9, 99, 999, 9999, 99999, 999999, 9999999]
9 :  [0, 9, 99, 999, 9999, 99999, 999999, 9999999]

2 :  [0, 8, 88, 898, 8998, 89998, 899998, 8999998]
4 :  [0, 8, 88, 888, 8888, 88988, 889988, 8899988]
8 :  [0, 8, 88, 888, 8888, 88888, 888888, 8889888]

5 :  [0, 5, 55, 595, 5995, 59995, 599995, 5999995]

6 :  [0, 6, 66, 888, 8778, 89898, 897798, 8998998]

7 :  [0, 7, 77, 959, 9779, 99799, 999999, 9994999]
*/

int stom(const string& s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans * 10 + s[i] - '0') % 7;
    }
    return ans;
}

class Solution {
public:
    string largestPalindrome(int n, int k) {
        set<int> s1 {1, 3, 9}, s2 {2, 4, 8};
        if (s1.contains(k)) {
            return string(n, '9');
        }
        if (s2.contains(k)) {
            int m = __lg(k);
            return n >= m * 2 ? string(m, '8') + string(n - m * 2, '9') + string(m, '8') : string(n, '8');
        }
        if (k == 5) {
            return n > 2 ? string(1, '5') + string(n - 2, '9') + string(1, '5') : string(n, '5');
        }

        if (k == 7) {
            int m = (n - 1) / 2;
            int mx = 0;
            for (int i = 0; i < pow(10, (n - 2 * m)); ++i) {
                if ((i < 10 || i % 10 == i / 10) && stom(string(m, '9') + to_string(i) + string(m, '9')) == 0) {
                    mx = max(mx, i);
                }
            }
            return string(m, '9') + to_string(mx) + string(m, '9');
        }

        if (n <= 2) {
            return string(n, '6');
        }
        string ans(n, '9');
        ans[0] = '8', ans[n - 1] = '8';
        if (n & 1) {
            ans[n / 2] = '8';
        } else {
            ans[n / 2] = '7', ans[n / 2 - 1] = '7';
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}