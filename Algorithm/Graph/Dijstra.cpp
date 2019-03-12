//
// Created by sgh on 2019-03-12.
//

int cost[MAX_V][MAX_V];     // cost[u][v]表示边e=(u, v)的权值，不存在时为INF
int d[MAX_V];               // 顶点s出发的最短距离
bool used[MAX_V];           // 已经使用过的点
int v;                      // 顶点数

// 求从起点s出发到各个顶点的最短距离
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while (true) {
        int v = -1;
        //从尚未使用过的顶点中选出一个距离最小的顶点
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }
        if (v == -1) {
            break;
        }
        used[v] = true;
        for (int u = 0; u < V; u++) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

struct edge {
    int to, cost;
};
typedef pair<int, int> P; // first是最短距离, second是顶点的编号

int V;
vector <edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    // 通过指定greater<P>参数，堆按照first从小到大的顺序取出值
    priority_queue <P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}