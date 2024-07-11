#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 使用二叉堆优化的 Prim 算法。
const int N = 5050, M = 2e5 + 10;

struct E {
    int v, w, x;
} e[M * 2];

int n, m, h[N], cnte;

void adde(int u, int v, int w) {
    e[++cnte] = E {v, w, h[u]};
    h[u] = cnte;
}

struct S {
    int u, d;
};

bool operator<(const S& x, const S& y) {
    return x.d > y.d;
}

priority_queue<S> q;
vector<int> dis(N, 0x3f);
bool vis[N];

int res = 0, cnt = 0;

void Prim() {
    dis[1] = 0;
    q.emplace(1, 0);
    while (!q.empty()) {
        if (cnt >= n) {
            break;
        }

        int u = q.top().u, d = q.top().d;
        q.pop();

        if (vis[u]) {
            continue;
        }

        vis[u] = 1;
        ++cnt;
        res += d;
        for (int i = h[u]; i; i = e[i].x) {
            int v = e[i].v, w = e[i].w;
            if (w < dis[v]) {
                dis[v] = w;
                q.emplace(v, w);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        adde(u, v, w), adde(v, u, w);
    }
    Prim();

    if (cnt == n) {
        cout << res;
    } else {
        cout << "No MST.";
    }
    return 0;
}