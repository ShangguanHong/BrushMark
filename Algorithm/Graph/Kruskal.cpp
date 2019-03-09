//
// Created by fate on 2019/3/9.
//
// 最小生成树的Kruskal算法

struct edge {
    int u, v, cost
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal() {
    sort(es, es + E, comp);
    init_union_find(V); // 初始化并查集
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}