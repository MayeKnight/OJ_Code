#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        long long ans = 0;
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            ump[num].emplace_back(i);

            if (ump.contains(num - k)) {
                for (int& v : ump[num - k]) {
                    ans = max(ans, pre[i] - pre[v]);
                }
            }
            if (ump.contains(num + k)) {
                for (int& v : ump[num + k]) {
                    ans = max(ans, pre[i] - pre[v]);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}