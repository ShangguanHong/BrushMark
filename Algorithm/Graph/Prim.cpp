//
// Created by fate on 2019/3/9.
//
//最小生成树的Prim算法

#include <bits/stdc++.h>

using namespace std;

int cost[MAX_V][MAX_V]; // cost[u][v]代表边e=(u, v)的权值(不存在时设为INF)
int mincost[MAX_V];     // 从集合X出发的边到每个顶点的最小权值
bool used[MAX_V];       // 定点i是否包含在集合X中
int V;                  // 顶点数

int prim() {
    for (int i = 0; i < V; i++) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || mincost[v] > mincost[u])) {
                v = u;
            }
        }
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        for (int u = 0; u < V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

