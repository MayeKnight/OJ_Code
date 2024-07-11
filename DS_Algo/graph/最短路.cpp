#include <bits/stdc++.h>

#define N 100

using namespace std;
using ll = long long;

static constexpr int inf = 0x3f3f3f3f;

/*
    对于边权为正的图，任意两个结点之间的最短路，不会经过重复的结点，不会经过重复的边
    对于边权为正的图，任意两个结点之间的最短路，任意一条的结点数不会超过 n，边数不会超过 n-1。
*/

// Floyd-Warshall 求解图中任意两点之间的最短路径
// 适用于任何图，不管有向无向，边权正负，但是最短路必须存在。（不能有个负环）
vector<vector<int>> shortestPathFloydWarshall(int n, vector<vector<int>>& edges) { // 顶点数、边列表
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) { // 初始化，保证 g[i][i] = 0
        g[i][i] = 0;
    }

    for (const auto& e : edges) {
        int v = e[0], w = e[1], dis = e[2];
        g[v][w] = g[w][v] = min(g[v][w], dis);
    }

    // g[k][i][j] 表示「经过若干个编号不超过 k 的中间节点」时，从 i 到 j 的最短路长度，其中第一维可以压缩掉
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (g[i][k] == inf) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                g[i][j] =
                    min(g[i][j], // 不经过 k 的最短路
                        g[i][k] + g[k][j]); // 经过了 k 的最短路
            }
        }
    }

    // 如果出现 g[i][i] < 0 则说明有负环

    // 动态加边
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    function<void(int, int, int)> addEdge = [&](int from, int to, int dis) {
        if (dis >= g[from][to]) { // 无法让任何最短路变短
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][from] + dis + g[to][j]);
            }
        }
    };

    return g;
}

// Bellman–Ford
// 一种基于松弛（relax）操作的最短路算法，可以求出有负权的图的最短路，并可以对最短路不存在的情况进行判断。