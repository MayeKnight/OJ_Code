#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<pair<int, int>> s;
        for (int i = 0; i < n - 1; ++i) {
            s.emplace(i, i + 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];

            auto iter = s.lower_bound({u, -1});
            if (iter != s.end() && iter->second < v) {
                for (; iter != s.end() && iter->second <= v;) {
                    iter = s.erase(iter);
                }
                s.emplace(u, v);
            }

            ans.emplace_back(s.size());
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> vec {
        {1, 4},
        {2, 4},
    };
    sol.shortestDistanceAfterQueries(5, vec);

    return 0;
}