#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;

        function<void(int)> dfs = [&](int i) -> void {
            if (vec.size() > k) {
                return;
            }

            if (accumulate(vec.begin(), vec.end(), 0) > n) {
                return;
            }

            if (vec.size() == k && accumulate(vec.begin(), vec.end(), 0) == n) {
                ans.emplace_back(vec);
                return;
            }

            for (int j = i; j > 0; --j) {
                vec.emplace_back(j);
                dfs(j - 1);
                vec.pop_back();
            }
        };

        dfs(9);
        return ans;
    }
};

class Solution_1 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;

        function<void(int, int)> func = [&](int i, int total) -> void {
            int d = k - vec.size();
            if (total < 0 || total > (i + i - d + 1) * d / 2) {
                return;
            }

            if (d == 0) {
                ans.emplace_back(vec);
                return;
            }

            for (int j = i; j >= d; --j) {
                vec.emplace_back(j);
                func(j - 1, total - j);
                vec.pop_back();
            }
        };

        func(9, n);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;

        function<void(int, int)> f = [&](int i, int t) -> void {
            int d = k - vec.size();
            if (t < 0 || t > (i + i - d + 1) * d / 2) {
                return;
            }

            //* 不需要额外判断 t == 0。
            if (d == 0) {
                ans.emplace_back(vec);
                return;
            }
            
            // 选
            vec.emplace_back(i);
            f(i - 1, t - i);
            vec.pop_back();

            // 不选
            if (i > d) {
                f(i - 1, t);
            }
        };

        f(9, n);
        return ans;
    }
};