#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    树上倍增：
        要预处理哪些节点？
*/

class TreeAncestor {
private:
    vector<vector<int>> pa;

public:
    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);
        pa.resize(n, vector<int>(m, -1));

        // 遍历每一个节点，令第一个索引为父节点
        for (int i = 0; i < n; ++i) {
            pa[i][0] = parent[i];
        }
        // 遍历数组，填充索引
        for (int j = 0; j < m - 1; ++j) {
            for (int i = 0; i < n; ++i) {
                int p = pa[i][j];
                if (p != -1) {
                    pa[i][j + 1] = pa[p][j]; // 更新下一个索引
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (; k && ~node; k &= k - 1) {
            node = pa[node][__builtin_ctz(k)];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */