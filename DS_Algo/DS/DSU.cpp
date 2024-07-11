#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    并查集是一种用于管理元素所属集合的数据结构，实现为一个森林，其中每棵树表示一个集合，树中的节点表示对应集合中的元素。
    （并查集无法以较低复杂度实现集合的分离。）

        合并（Union）：合并两个元素所属集合（合并对应的树）
            启发式合并：可以将节点较少或深度较小的树连到另一棵，以免发生退化。

        查询（Find）：沿着树向上移动，查询某个元素所属集合，直至找到根节点。这可以用于判断两个元素是否属于同一集合。
            路径压缩：查询过程中经过的每个元素都属于该集合，我们可以将其直接连到根节点以加快后续查询。

        删除：要删除一个叶子节点，可以将其父亲设为自己。
        （移动与删除类似）
*/

struct dsu {
    vector<size_t> pa, size;

    // 预先为每个节点制作副本，并将其副本作为父亲。
    explicit dsu(size_t size_) : pa(size_ * 2), size(size_ * 2, 1) {
        iota(pa.begin(), pa.begin() + size_, size_);
        iota(pa.begin() + size_, pa.end(), size_);
    }

    size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    void unite(size_t x, size_t y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }

        if (size[px] < size[py]) {
            swap(px, py);
        }

        pa[py] = px;
        size[px] += size[py];
    }

    void erase(size_t x) {
        --size[find(x)];
        pa[x] = x;
    }

    void move(size_t x, size_t y) {
        size_t px = find(x), py = find(y);
        if (px == py) {
            return;
        }

        pa[x] = py;
        --size[px], ++size[py];
    }
};
