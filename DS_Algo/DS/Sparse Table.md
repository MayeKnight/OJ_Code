倍增：不能出现包含的情况（即，后面的右端点不会比前面靠左）

# ST表的适用范围

可重复贡献问题（RMQ【最大值、最小值】、区间GCD、按位与、按位或等，对应的运算还必须满足`结合律`）
（区间和不符合要求）

基于倍增思想，O(nlog n)预处理，O（1）回答询问，但不支持修改。

# ST表的列

给定一个正数 x，寻找不大于 x 的最大的 2 的幂
```cpp
cout << __lg(x) << "\n";

// 实现如下：
void solve() {
    int power = 0;
    while((1 << power) <= (x >> 1)) {
        power++;
    }
    cout << format("最大的幂次是 {}\n", power);
}
```

## ST表代码 1（倍增）

```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Guard> vec(n * 2);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (r < l) { // 延伸
            r += m;
        }
        vec[i] = Guard(i, l, r);
        vec[i + n] = Guard(i, l + m, r + m); // 复制
    }

    //! 注意排序操作与复制操作的影响
    ranges::sort(vec, [&](const Guard& a, const Guard& b) { return a.l < b.l; });

    // 倍增，预处理（从一名战士开始，直到另一名战士的左端点大于该战士的右端点）
    int len = __lg(n);
    vector<vector<int>> path(n * 2, vector<int>(len + 1));
    auto init = [&]() -> int {
        for (int i = 0, p = i; i < n * 2; ++i) {
            while (p < 2 * n && vec[p].l <= vec[i].r) {
                p++;
            }
            path[i][0] = p - 1;
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < n * 2; ++j) {
                path[j][i] = path[path[j][i - 1]][i - 1];
            }
        }
        return 0;
    }();

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int end = vec[i + n].l;
        int cur = i, res = 1;
        // 从后往前找跳跃的有效值
        for (int j = len; j >= 0; --j) {
            int& next = path[cur][j];
            if (next && vec[next].r < end) {
                res += 1 << j;
                cur = next;
            }
        }
        ans[vec[i].id] = res + 1; //! 注意编号
    }

    for (int& v : ans) {
        cout << v << " ";
    }
}
```

例题：
https://www.luogu.com.cn/problem/P4155  （拆环成链）


## ST表代码 2    维护最大值、最小值

```cpp
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int len = __lg(n);
    vector<vector<array<int, 2>>> st(n, vector<array<int, 2>>(len + 1));
    auto init = [&]() -> int {
        for (int i = 0; i < n; ++i) {
            st[i][0] = {vec[i], vec[i]};
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                auto& [maxV, minV] = st[j][i];
                // 令 f(i,j) 表示区间 [i,i+2^j-1] 的最大值。
                maxV = max(st[j][i - 1][0], st[j + (1 << (i - 1))][i - 1][0]);
                minV = min(st[j][i - 1][1], st[j + (1 << (i - 1))][i - 1][1]);
            }
        }
        return 0;
    }();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int len = __lg(r - l + 1);
        array<int, 2>& ll = st[l][len];
        array<int, 2>& rr = st[r - (1 << len) + 1][len];
        cout << max(ll[0], rr[0]) - min(ll[1], rr[1]) << "\n";
    }
}
```

例题：
https://www.luogu.com.cn/problem/P3865  （模板题：区间最大值）
https://www.luogu.com.cn/problem/P2880  （平衡最大值最小值之差）

## ST表代码 3    求最大公约数

```cpp
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int len = __lg(n);
    vector<vector<int>> st(n, vector<int>(len + 1));
    auto init = [&]() -> int {
        for (int i = 0; i < n; ++i) {
            st[i][0] = vec[i];
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }
        return 0;
    }();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int s = __lg(r - l + 1);
        cout << gcd(st[l][s], st[r - (1 << s) + 1][s]) << "\n";
    }
}
```

例题：
https://www.luogu.com.cn/problem/P1890

