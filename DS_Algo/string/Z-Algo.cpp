#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
*   Z 函数（扩展KMP）
        对于长度为 n 的字符串 s，定义函数 z[i] 表示 s 和 s[i, n-1] （即以 s[i] 开头的后缀）的最长公共前缀（LCP）的长度
*/

// 朴素算法：
// vector<int> Z_Algo(string s) {
//     int n = s.size();
//     vector<int> z(n);
//     for (int i = 1; i < n; ++i) {
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             z[i]++;
//         }
//     }
//     return z;
// }

//* 线性算法：
//      对于 i，称闭区间 [i, i + z[i] - 1] 为 i 的匹配段（Z-box），相当于一段窗口
vector<int> Z_Algo_1(string s) {
    int n = s.size();
    vector<int> z(n);

    // l, r 表示 Z-box 的左右端点，在匹配的过程中，保证 l <= i
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        //* z[i-l] 表明了 “匹配了多少个字符” 以及 “到哪个字符不匹配”
        // z[i - l] < r - i + 1 表示：匹配段不超过 Z-box 最右端
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            // 能够匹配的字符已经超出 Z-box，当前匹配信息已知
            z[i] = max(0, r - i + 1);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
        }

        // 更新 新匹配段 Z-box 的左右端点
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

//* （去分支）
vector<int> Z_Algo_2(string s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i, r = i + z[i]++;
        }
    }
    return z;
}

vector<int> Z_Algo_3(string s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, c = 1, r = 1, length; i < n; ++i) {
        length = r > i ? min(r - i, z[i - c]) : 0;

        while (i + length < n && s[i + length] == s[length]) {
            length++;
        }

        if (i + length > r) {
            r = i + length, c = i;
        }

        z[i] = length;
    }

    return z;
}