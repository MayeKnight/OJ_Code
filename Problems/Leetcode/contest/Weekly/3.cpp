#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        long long ans = 0, cnt = 1;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '0') {
                ans += cnt;
            }
            while (i < n - 1 && s[i + 1] != '1') {
                i++;
            }
            cnt++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}