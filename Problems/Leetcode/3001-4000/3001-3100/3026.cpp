#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        unordered_map<int, int> ump;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            int& num = nums[i];
            pre[i + 1] = pre[i] + num;

            if (ump.contains(num - k)) {
                ans = max(ans, pre[i + 1] - pre[ump[num - k]]);
            }
            if (ump.contains(num + k)) {
                ans = max(ans, pre[i + 1] - pre[ump[num + k]]);
            }

            if (!ump.contains(num) || pre[i] - pre[ump[num]] <= 0) {
                ump[num] = i;
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}