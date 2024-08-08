#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    每次新插入一个元素，修改的线段树只与插入的元素有关（只有添加的值到根节点的一条链发生了变化）。

    作用: 查询任意区间第 k 大/小的值。
*/
struct Node {
    int l, r, cnt;
};

class SegTree {
private:
    int n = 0, len = 0, top = 0;
    vector<Node> f;
    vector<int> root;

private:
    int clone(int pre) {
        // pre 为原始节点的编号
        ++this->top;
        f[this->top].l = f[pre].l, f[this->top].r = f[pre].r, f[this->top].cnt = f[pre].cnt + 1;
        return this->top;
    }

    int build(int node, int l, int r) {
        node = ++this->top;
        f[node].cnt = 0;
        if (l == r) {
            return node;
        }
        int mid = l + (r - l) / 2;
        f[node].l = build(node, l, mid);
        f[node].r = build(node, mid + 1, r);
        return node;
    }

    int update(int pre, int l, int r, int loc) {
        int cur = clone(pre);
        if (l == r) {
            return cur;
        }
        int mid = l + (r - l) / 2;
        if (loc <= mid) {
            f[cur].l = update(f[cur].l, l, mid, loc);
        } else {
            f[cur].r = update(f[cur].r, mid + 1, r, loc);
        }
        return cur;
    }

    // root[l-1], root[r], 1, (unique)size, k
    int query(int pre, int cur, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int ans = 0;
        int l1 = f[cur].l, l2 = f[pre].l; // 通过两个时刻同一位置的 cnt 值相减，得到 [l, r] 查询区间内有多少个元素位于这个节点的子区间内
        int cnt = f[l1].cnt - f[l2].cnt;
        int mid = l + (r - l) / 2;
        if (cnt >= k) {
            return query(f[pre].l, f[cur].l, l, mid, k);
        }
        return query(f[pre].r, f[cur].r, mid + 1, r, k - cnt);
    }

public:
    SegTree() {}
    SegTree(int n) : n(n), f(n << 5), root(n << 5) {}
    SegTree(vector<int>& vec) : SegTree(vec.size()) {
        vector<int> res(vec);

        ranges::sort(res);
        res.erase(unique(res.begin(), res.end()), res.end());
        this->len = res.size();

        root[0] = build(0, 1, this->len); // 构建空树
        for (int i = 0; i < n; ++i) {
            int loc = ranges::lower_bound(res, vec[i]) - res.begin() + 1; // 下标从 1 开始
            root[i + 1] = update(root[i], 1, this->len, loc);
        }

        vec = std::move(res);
    }

    int query(int l, int r, int k) { return query(root[l - 1], root[r], 1, len, k); }
};
// 注意下标从 1 开始，同时传入的 vec 参数将被修改便于后续查询。

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    SegTree tree(vec);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        cout << vec[tree.query(l, r, k) - 1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
