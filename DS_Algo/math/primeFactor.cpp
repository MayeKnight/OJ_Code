#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* 寻找质因数 */

// * plain:
void find(int n) {
    vector<int> ans;

    int x = n;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            x /= i;
            ans.emplace_back(i);
        }
    }

    if (x > 1) ans.emplace_back(x);
}

int main() {
    find(1119);

    return 0;
}

// * problems:

// https://leetcode.cn/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
int smallestValue(int n) {
    while (1) {
        int x = n, s = 0, i = 2;
        while (i * i <= x) {
            while (x % i == 0) {
                s += i;
                x /= i;
            }
            i++;
        }
        if (x > 1) {
            s += x;
        }
        if (s == n) {
            return n;
        }

        n = s;
    }
}

// https://leetcode.cn/problems/distinct-prime-factors-of-product-of-array/
int distinctPrimeFactors(vector<int>& nums) {
    unordered_set<int> set;

    for (int& num : nums) {
        int x = num, i = 2;
        while (i * i <= x) {
            while (x % i == 0) {
                x /= i;
                set.emplace(i);
            }
            i++;
        }

        if (x > 1) {
            set.emplace(x);
        }
    }

    return set.size();
}
