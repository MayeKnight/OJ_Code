#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> set {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        for (char ch : s) {
            if (set.contains(ch)) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    return 0;
}