#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt[26];
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a'].emplace_back(i);
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int val = cnt[i].size();
            if (val & 1) {
                ans++;
            } else if (val > 0) {
                ans += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}