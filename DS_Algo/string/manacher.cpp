#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * manacher:
 *
 * 扩展串中的回文半径和真实回文长度的对应：真实长度 = p[i] - 1
 * 扩展回文串结尾下标和真实回文串终止位置的对应：真实回文串终止位置 = 扩展回文串结尾下标 / 2
 *      （真实回文串终止位置指不能满足条件的第一个字符）
 *
 * · 求回文子串数量
 */

int manacher(string s) {
    int n = s.size() * 2 + 1; // 处理后的字符数组长度
    char ss[n]; // 处理后的字符数组

    //* process
    for (int i = 0, j = 0; i < n; ++i) {
        ss[i] = (i & 1) == 0 ? '#' : s[j++];
    }

    int res[n]; // 记录扩散中心能构建的回文串的回文半径
    int maxV = 0; // 记录最大回文串真实长度
    for (int i = 0, center = 0, r = 0, length; i < n; ++i) {
        length = r > i ? min(res[2 * center - i], r - i) : 1;

        //* Brute Force
        while (i + length < n && i - length >= 0 && ss[i + length] == ss[i - length]) {
            length++;
        }

        //* update
        if (i + length > r) {
            r = i + length, center = i;
        }
        if (length > maxV) {
            maxV = length - 1;
        }

        //* record
        res[i] = length;
    }

    return maxV;
}