#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    更一般的解法
*/

class Solution {
public:
    string largestPalindrome(int n, int k) {
        // 状态 (i, j) 表示 当前 i 位填入的数字 mod k 为 j
        // 从大到小枚举数字 d，那么 j2 = (j + d * (10^i + 10^(n-1-i))) mod k
        // 从 (i, j) 到 (i+1, j2) 之间连边，得到一个有向图
        // 问题变成从 (0, 0) 到 (m, 0) 的路径，其中 m = n/2 上取整（注意奇数特判）
        vector<int> p(n);
        p[0] = 1;
        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] * 10 % k;
        }

        string ans(n, '0');
        int m = (n + 1) / 2;
        vector vis(m + 1, vector<int>(k));
        auto dfs = [&](auto&& self, int i, int j) -> bool {
            if (i == m) {
                return j == 0;
            }
            vis[i][j] = 1;
            for (int d = 9; d >= 0; --d) {
                int j2 = (n % 2 == 1 && i == m - 1 ? (j + d * p[i]) % k : (j + d * (p[i] + p[n - 1 - i])) % k);
                if (vis[i + 1][j2] == 0 && self(self, i + 1, j2)) {
                    ans[i] = ans[n - 1 - i] = '0' + d;
                    return true;
                }
            }
            return false;
        };

        dfs(dfs, 0, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}