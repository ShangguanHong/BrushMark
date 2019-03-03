#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int n, m;
vector<int> tree[maxn];
int main() {
    cin >> n >> m;
    int a, k, b;
    for(int i = 0; i < m; i ++) {
        cin >> a >> k;
        for(int j = 0; j < k; j ++) {
            cin >> b;
            tree[a].push_back(b);
        }
    }
    queue<int> q;
    q.push(1);
    bool first = true;
    while(!q.empty()) {
        int size = q.size(), cnt = 0;
        for(int i = 0; i < size; i ++) {
            a = q.front();
            q.pop();
            if(tree[a].size() == 0) {
                cnt ++;
            } else {
                for(int j = 0; j < tree[a].size(); j ++) {
                    q.push(tree[a][j]);
                }
            }
        }
        if(first) {
            cout << cnt;
            first = false;
        } else {
            cout << " " << cnt;
        }
    }
    return 0;
}