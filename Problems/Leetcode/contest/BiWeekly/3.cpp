#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> vec(n / 2);
        for (int i = 0; i < n / 2; ++i) {
            if (nums[i] > nums[n - 1 - i]) {
                swap(nums[i], nums[n - 1 - i]);
            }
            map[nums[n - 1 - i] - nums[i]]++;
            vec[i] = max(k - nums[i], nums[n - 1 - i]);
        }

        ranges::sort(vec);

        int ans = INT_MAX;
        for (auto& [v, c] : map) {
            int cnt = (vec.end() - ranges::lower_bound(vec, v));
            ans = min(ans, n - cnt - c);
        }
        return ans;
    }
};

class TLE_Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> map;
        for (int i = 0; i < n / 2; ++i) {
            if (nums[i] > nums[n - 1 - i]) {
                swap(nums[i], nums[n - 1 - i]);
            }
            map[nums[n - 1 - i] - nums[i]]++;
        }

        int ans = INT_MAX;
        for (auto& [v, c] : map) {
            if (v > k) {
                break;
            }

            int cnt = 0;
            for (int i = 0; i < n / 2; ++i) {
                if (nums[n - 1 - i] - nums[i] == v) {
                    continue;
                }
                if (nums[i] + v <= k || nums[n - 1 - i] - v >= 0) {
                    cnt++;
                } else {
                    cnt += 2;
                }
            }

            ans = min(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {9, 2, 7, 7, 8, 9, 1, 5, 1, 9, 4, 9, 4, 7};
    sol.minChanges(nums, 9);

    /*
        [18,10,14,18,17,2,11,5]
        19
        输出 5  预期 2

        [9,2,7,7,8,9,1,5,1,9,4,9,4,7]
        9
        输出 5  预期 4
    */

    return 0;
}