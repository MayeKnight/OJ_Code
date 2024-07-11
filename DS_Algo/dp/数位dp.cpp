#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * * 数位DP：最终目的为计数
 * * 初始状态：         free == 0, fix == 0
 * * 1> 高位为 0        fix == 0
 * * 2> 高位较小且非 0  free == 1, fix == 1
 * * 3> 高位相等且非 0  free == 0, fix == 1
 */

/// @param digits   有序数组
/// @param num      限定的上界
/// @param offset
/// @param len      还没有确定的位数
/// @param free     是否可以自由选择
/// @param fix      是否已填充过数位
/// @return 不大于给定上界的整数个数（可以重复选择 digits 数位）
int f1(vector<int>& digits, int num, int offset, int len, int free, int fix) {
    if (len == 0) {
        return fix == 1 ? 1 : 0;
    }

    int ans = 0;
    int cur = (num / offset) % 10; // 当前位
    if (fix == 0) { // 之前没有填充过数位
        ans += f1(digits, num, offset / 10, len - 1, 1, 0);
    }

    // 不能自由选择的时候，需要做出来选择
    if (free == 0) { // 之前的数位与 num 相同
        for (int& i : digits) {
            if (i < cur) { // 当前数位选择了一个较小的
                ans += f1(digits, num, offset / 10, len - 1, 1, 1);
            } else if (i == cur) {
                ans += f1(digits, num, offset / 10, len - 1, 0, 1);
            } else {
                break;
            }
        }
    } else {
        ans += digits.size() * f1(digits, num, offset / 10, len - 1, 1, 1);
    }

    return ans;
}

int f2(vector<int>& digits, vector<int>& cnt, int num, int offset, int len) {
    if (len == 0) {
        return 1; // num 本身
    }

    int ans = 0;
    int cur = (num / offset) % 10; // 当前位
    for (int& i : digits) {
        if (i < cur) {
            ans += cnt[len - 1];
        } else if (i == cur) {
            ans += f2(digits, cnt, num, offset / 10, len - 1);
        } else {
            break;
        }
    }

    return ans;
}

int func(vector<int>& digits, int num) {
    // 计算 num 的位数
    int tmp = num / 10;
    int len = 1;
    int offset = 1; // 用来提取某一位
    while (tmp) {
        tmp /= 10;
        len++;
        offset *= 10;
    }

    /* Solution 1 */
    // return f1(digits, num, offset, len, 0, 0);

    /* Solution 2 */
    // cnt[i] 表示 前缀比 num 小，剩下 i 位没有确定的排列数目
    vector<int> cnt(len);
    cnt[0] = 1;
    int ans = 0, n = digits.size();
    for (int i = n, k = 1; k < len; ++k, i *= n) {
        cnt[k] = i;
        ans += i; // 把高位为 0 的小于 num 的数的数目累加
    }

    return ans + f2(digits, cnt, num, offset, len);
}
