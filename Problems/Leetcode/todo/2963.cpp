#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, pair<int, int>> ump;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];

            if (ump.contains(x)) {
                ump[x].second = i; // 更新右端点
            } else {
                ump[x] = {i, i};
            }
        }

        vector<pair<int, int>> vec;
        for (auto& [_, p] : ump) {
            vec.emplace_back(p);
        }
        sort(vec.begin(), vec.end(), [](const auto& p1, const auto& p2) { return p1.first < p2.first; });

        int ans = 1;
        int maxR = vec[0].second;
        for (const auto& v : vec) {
            int l = v.first, r = v.second;
            if (l > maxR) {
                ans = ans * 2 % mod;
            }
            maxR = max(maxR, r);
        }

        return ans;
    }
};