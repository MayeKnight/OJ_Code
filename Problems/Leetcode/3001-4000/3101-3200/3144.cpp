#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> memo(n + 1, -1);
        memo[n] = 0;
        function<int(int)> dfs = [&](int x) -> int {
            int& res = memo[x];
            if (res != -1) {
                return res;
            }

            vector<int> nums(26);
            unordered_map<int, int> ump;
            int ans = INT_MAX;
            for (int i = x; i < n; ++i) {
                int num = nums[s[i] - 'a'];
                if (num > 0) {
                    ump[num]--;
                    if (ump[num] == 0) {
                        ump.erase(num);
                    }
                }
                nums[s[i] - 'a']++;
                num = nums[s[i] - 'a'];
                ump[num]++;

                if (ump.size() == 1) {
                    ans = min(ans, dfs(i + 1) + 1);
                }
            }
            return res = ans;
        };
        dfs(0);
        return memo[0];
    }
};

int main() {
    Solution sol;

    return 0;
}