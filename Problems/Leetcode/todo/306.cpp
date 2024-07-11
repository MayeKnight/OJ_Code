#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isAdditiveNumber_0(string num) {
        int n = num.length();
        vector<vector<long double>> ans;
        vector<long double> vec;

        function<bool(vector<long double>&)> check = [&](vector<long double>& v) -> bool {
            if (v.size() < 3) {
                return false;
            }

            for (int i = 2; i < v.size(); ++i) {
                if (v[i] != v[i - 1] + v[i - 2]) {
                    return false;
                }
            }

            return true;
        };

        function<void(int, int)> f = [&](int i, int start) -> void {
            if (i == n) {
                ans.emplace_back(vec);
                return;
            }
            // 不选
            if (i < n - 1) {
                f(i + 1, start);
            }
            if (i > start && num[start] == '0') {
                return;
            }
            long double digit = stoll(num.substr(start, i - start + 1));
            // 选
            int len = vec.size();
            if (len < 2 || digit == vec[len - 1] + vec[len - 2]) {
                vec.emplace_back(digit);
                f(i + 1, i + 1);
                vec.pop_back();
            }
        };
        f(0, 0);

        // function<void(int)> f = [&](int i) -> void {
        //     if (i == n) {
        //         if (vec.size() > 2) {
        //             ans.emplace_back(vec);
        //         }
        //     }

        //     int len = vec.size();
        //     for (int j = i; j < n; ++j) {
        //         if (j > i && num[i] == '0') {
        //             continue;
        //         }

        //         long double digit = stold(num.substr(i, j + 1 - i));
        //         if (len <= 2 || digit == vec[len - 1] + vec[len - 2]) {
        //             vec.emplace_back(digit);
        //             f(j + 1);
        //             vec.pop_back();
        //         }
        //     }
        // };
        // f(0);

        for (vector<long double>& v : ans) {
            if (check(v)) {
                return true;
            }
        }

        return false;
    }

public:
    bool isAdditiveNumber_1(string num) {
        vector<long double> tmp;

        function<bool(string)> f = [&](string num) -> bool {
            int n = tmp.size();

            // 判断条件
            if (n >= 3 && tmp[n - 1] != tmp[n - 2] + tmp[n - 3]) {
                return false;
            }

            // 边界条件
            if (num.size() == 0 && n >= 3) {
                return true;
            }

            for (int i = 0; i < num.size(); ++i) {
                string cur = num.substr(0, i + 1);

                // 跳过非法情况
                if (cur[0] == '0' && cur.size() != 1) {
                    continue;
                }

                tmp.push_back(stold(cur));
                if (f(num.substr(i + 1))) {
                    return true;
                }
                tmp.pop_back();
            }

            return false;
        };

        return f(num);
    }

public:
    bool isAdditiveNumber_2(string num) {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (valid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int secondStart, int secondEnd, string num) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};