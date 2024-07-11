线段树：（维护区间信息）
    O(logN) 实现单点修改、区间修改、区间查询（区间求和、最大值、最小值）等。
    父范围的信息可以 O(1) 从子范围的信息加工得到。

    将每个长度不为 1 的区间划分为左右两个区间递归求解。

    用数组 d 保存线段树结构，di 保存树上编号为 i 的节点的值，
    如果 di 表示区间 [s, t]，那么它的左儿子表示区间 [s, (s+t)/2]，右儿子表示区间 [(s+t)/2+1, t]。

> l, r 表示查询区间，s, t 表示当前节点包含区间

```cpp
void build(int s, int t, int p) { // 当前节点编号为 p
    if (s == t) {
        d[p] = a[s];
        return;
    }

    int mid = s + (t - s) / 2;
    build(s, mid, p*2);
    build(mid+1, t, p*2+1);

    d[p] = d[p*2] + d[p*2+1]; // 此处维护区间和
}
```

一般地，如果要查询的区间是 [l, r]，则可以将其拆成最多 O(logN) 个极大的区间，合并这些区间即可。
```cpp
int querySum(int l, int r, int s, int t, int p) {
    if(l <= s && r >= t) {
        return d[p]; // 当前区间为询问区间的子集时直接返回当前区间的和
    }

    int mid = s + (t - s) / 2;
    int sum = 0;
    if(l <= mid) { // [s, mid]
        sum += querySum(l, r, s, mid, p*2);
    }
    if(r > mid) { // [mid+1, t]
        sum += querySum(l, r, mid+1, t, p*2+1);
    }
    return sum;
}
```

> tag 表示标记数组

区间修改与懒标记（延迟对节点信息的更改，减少不必要的操作次数）
子范围的懒标记更新信息发生的时间早于父范围的懒标记更新信息
```cpp
// 区间修改（添加某个值）
void update(int l, int r, int c, int s, int t, int p) { // c 为修改信息
    if(l <= s && r >= t) {
        d[p] += (t - s + 1) * c;
        tag[p] += c;
        return;
    }

    int mid = s + (t - s) / 2;
    if(tag[p] && s != t) { // 区间，标记
        d[p*2] += tag[p] * (mid - s + 1);
        d[p*2+1] += tag[p] * (t - mid);

        // 标记下发
        tag[p*2] += tag[p];
        tag[p*2+1] += tag[p];
        tag[p] = 0;
    }

    if(l <= mid) {
        update(l, r, c, s, mid, p*2);
    }
    if(r > mid) {
        update(l, r, c, mid+1, t, p*2+1);
    }
    d[p] = d[p*2] + d[p*2+1];
}

// 区间求和
int querySum(int l, int r, int s, int t, int p) {
    if(l <= s && r >= t) {
        return d[p];
    }

    int mid = s + (t - s) / 2;
    if(tag[p]) {
        d[p*2] += tag[p] * (mid - s + 1);
        d[p*2+1] += tag[p] * (t - mid);

        tag[p*2] += tag[p];
        tag[p*2+1] += tag[p];
        tag[p] = 0;
    }

    int sum = 0;
    if(l <= mid) { // [s, mid]
        sum += querySum(l, r, s, mid, p*2);
    }
    if(r > mid) { // [mid+1, t]
        sum += querySum(l, r, mid+1, t, p*2+1);
    }
    return sum;
}
```

> v 表示额外数组，存放修改的值

```cpp
// 区间修改（修改为某个值）
void update(int l, int r, int c, int s, int t, int p) {
    if(l <= s && r >= t) {
        d[p] = c * (t - s + 1);
        tag[p] = c;
        return;
    }

    int mid = s + (t - s) / 2;
    if(v[p]) {
        d[p*2] = tag[p] * (mid - s + 1);
        d[p*2+1] = tag[p] * (t - mid);

        tag[p*2] = tag[p*2+1] = tag[p];

        v[p*2] = v[p*2+1] = 1;
        v[p] = 0;
    }

    int sum = 0;
    if(l <= mid) {
        sum += querySum(l, r, s, mid, p*2);
    }
    if(r > mid) {
        sum += querySum(l, r, mid+1, t, p*2+1);
    }
    return sum;
}
```
