#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            int dis = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dis > k) {
                s[i] -= k;
                break;
            }
            s[i] = 'a';
            k -= dis;
        }
        return s;
    }

public:
    string my_getSmallestString(string s, int k) {
        for (int i = 0; i < s.size() && k > 0; ++i) {
            if (s[i] == 'a') {
                continue;
            }

            int diff;
            if (s[i] + k <= 'z') {
                diff = s[i] - 'a';
            } else {
                diff = min(s[i] - 'a', 'z' - s[i] + 1);
            }
            
            if (diff <= k) {
                s[i] = 'a';
                k -= diff;
            } else {
                s[i] -= k;
                return s;
            }
        }

        return s;
    }
};