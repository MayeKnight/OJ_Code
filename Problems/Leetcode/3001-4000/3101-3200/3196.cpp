#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector f(n, vector<long long>(2, LLONG_MIN / 2));
        f[0][0] = nums[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]) + nums[i];
            f[i][1] = f[i - 1][0] - nums[i];
        }
        return ranges::max(f.back());
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, -2, 3, 4};
    sol.maximumTotalCost(nums);

    return 0;
}