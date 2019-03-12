//
// Created by fate on 2019/3/9.
//
// 单源最短路径的Bellman-Ford算法

// 从定点from指向顶点to的权值为cost的边
struct edge {
    int from, to, cost;
};

edge es[MAX_E]; // 边

int d[MAX_V]; // 最短距离
int V, E; // V是顶点数, E是边数

// 求解从顶点s出发到所有点的最短距离
void shortest_path(int s) {
    for (int i = 0; i < V; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                update = true;
            }
            if (!update) break;
        }
    }
}

// 如果返回true则存在负圈
bool find_negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                // 如果第n此仍更新了, 则存在负圈
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}
