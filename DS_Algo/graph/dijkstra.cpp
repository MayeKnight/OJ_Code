#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

/*
### dijkstra 算法：
    > 求解 `非负权重加权有向图` 上 `单源最短路`
    > operations :
        · 定义 dis[u] 表示从起点到 q 结点的最短路径长度
        · 对边进行分类： 已经确定了最短路长度的点的集合 s 没有确定最短路长度的点的集合 t
        · 从集合 t 中选取 dis 值最小的结点，将其加入到集合 s 中，并把该节点的所有出边进行松弛

    // g[i][j] 表示从 i 到 j 的边权
    // dis[i] 表示从起点 k 到节点 i 的最短路长度
    //
    // 更新节点 k 到邻居 y 的最短路，即更新 dis[y] 为 g[k][y]
    // 取除了节点 k 以外的 dis[i] 的最小值
    //     · 假定最小值对应节点为 m，则 dis[m] 已经是 k 到 m 的最短路长度
    // 用节点 m 到邻居 y 的边权 g[m][y] 更新 dis[y]，即 dis[m] + g[m][y] < dis[y] 时更新
    // 取除了节点 k，m 以外的 dis[i] 的最小值，重复上述过程

    ! 点的编号从 1 开始
*/

namespace dijkstra {
    struct edge {
        int to, w;
    };

    vector<edge> adj[100005]; // n + 1

    void solve() {
        int n, m, s; // 点的个数，有向边个数，出发点编号
        cin >> n >> m >> s;

        vector<int> dis(n + 1, INT_MAX), vis(n + 1); // !注意初始值
        for (int i = 0; i < m; ++i) {
            int u, v, w; // from, to, weight
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        }

        /* 朴素 稠密图 */
        dis[s] = 0;
        auto plain_dijkstra = [&](int s) -> void {
            for (int i = 1; i < n; ++i) {
                int cur = 0;
                for (int j = 1; j <= n; ++j) {
                    if (vis[j] == 0 && dis[j] < dis[cur]) {
                        cur = j;
                    }
                }
                vis[cur] = 1;

                for (auto& [to, w] : adj[cur]) {
                    if (dis[to] > dis[cur] + w) {
                        dis[to] = dis[cur] + w;
                    }
                }
            }
        };
        plain_dijkstra(s);

        /* 堆优化 稀疏图 */
        auto dijkstra = [&](int s) -> void {
            dis[s] = 0;

            using PII = pair<int, int>;
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            pq.emplace(0, s); // dis[k], k
            while (!pq.empty()) {
                auto [d, cur] = pq.top();
                pq.pop();

                if (d > dis[cur]) {
                    continue;
                }
                for (auto& [to, w] : adj[cur]) {
                    if (dis[to] > d + w) {
                        dis[to] = d + w;
                        pq.emplace(dis[to], to);
                    }
                }
            }
        };
        dijkstra(s);

        for (int i = 1; i <= n; ++i) {
            cout << dis[i] << " ";
        }
    }
} // namespace dijkstra