#include <algorithm>
#include <iostream>
#include <vector>

#define inf 10000000000
using namespace std;

int a[35010], b[35010];
long long sum1[35010], sum2[35010];
int le[35010]; // 每个数最长的以其结尾的不下降子序列长度
long long dp[35010];
int lin[35010], ln; // 算最长不下降子序列所用序列
vector<int> v[35010];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - i;
        dp[i] = inf;
    }
    int pl;
    for (int i = 1; i <= n; ++i) {
        if (!ln || lin[ln - 1] <= b[i]) {
            lin[ln++] = b[i];
            v[ln].push_back(i);
            le[i] = ln;
        } else {
            pl = upper_bound(lin, lin + ln, b[i]) - lin;
            lin[pl] = b[i];
            v[pl + 1].push_back(i);
            le[i] = pl + 1;
        }
    }
    cout << n - ln << endl;
    // 第一问结束

    v[0].push_back(0);
    b[0] = -200000; // 虚拟b(0)
    le[n + 1] = ln + 1;
    b[n + 1] = 200000;
    dp[n + 1] = inf; // 虚拟b(n+1)

    for (int j = 1; j <= n + 1; ++j) // 枚举j
        for (int p = 0; p < v[le[j] - 1].size(); ++p) {
            int i = v[le[j] - 1][p]; // 枚举i
            if (i > j || b[i] > b[j]) continue;

            sum1[i] = sum2[j] = 0;
            for (int q = i + 1; q < j; ++q) sum1[q] = sum1[q - 1] + abs(b[q] - b[i]);
            for (int q = j - 1; q > i; --q) sum2[q] = sum2[q + 1] + abs(b[q] - b[j]);
            // 两个前缀和

            long long ans = inf;
            for (int k = i; k < j; ++k) ans = min(ans, sum1[k] + sum2[k + 1]);
            dp[j] = min(dp[j], dp[i] + ans);
        }
    cout << dp[n + 1];
    // 第二问结束
    return 0;
}