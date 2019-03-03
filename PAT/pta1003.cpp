#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef struct {
    int to, val;
} Edge;
const int maxn = 500 + 5;
int city[maxn], sum[maxn], d[maxn], num[maxn];
int n, m, s, t;
vector<Edge> edge[maxn];

void dij() {
    fill(d, d + maxn, 1e6);
    priority_queue<P, vector<P>, greater<>> pq;
    d[s] = 0;
    num[s] = 1;
    sum[s] = city[s];
    pq.push(P(0, s));
    while(!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto e : edge[v]) {
            if(d[e.to] > d[v] + e.val) {
                num[e.to] = num[v];
                sum[e.to] = sum[v] + city[e.to];
                d[e.to] = d[v] + e.val;
                pq.push(P(d[e.to], e.to));
            } else if(d[e.to] == d[v] + e.val) {
                num[e.to] += num[v];
                sum[e.to] = max(sum[e.to], sum[v] + city[e.to]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    for(int i = 0; i < n; i ++) {
        cin >> city[i];
    }
    int from, to, val;
    for(int i = 0; i < m; i ++) {
        cin >> from >> to >> val;
        edge[from].push_back({to, val});
        edge[to].push_back({from, val});
    }
    dij();
    cout << num[t] << " " << sum[t];
    return 0;
}