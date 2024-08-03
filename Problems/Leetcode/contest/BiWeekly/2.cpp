#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rc = 0, cc = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[i][j] != grid[i][n - 1 - j]) {
                    rc++;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - 1 - i][j]) {
                    cc++;
                }
            }
        }

        return min(rc, cc);
    }
};

int main() {
    Solution sol;

    return 0;
}