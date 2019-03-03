//
// Created by fate on 2018/12/12.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n;
int m[maxn];
bool MAX = true, MIN = true;

void dfs(int idx, vector<int> t) {
    t.push_back(m[idx]);
    if (t.size() > 1 && (MAX || MIN)) {
        if (t[t.size() - 1] > t[t.size() - 2]) {
            MAX = false;
        }
        if (t[t.size() - 1] < t[t.size() - 2]) {
            MIN = false;
        }
    }
    if (idx * 2 + 1 <= n) {
        dfs(idx * 2 + 1, t);
        dfs(idx * 2, t);
    }
    else if (idx * 2 <= n) {
        dfs(idx * 2, t);
    }
    else {
        for (int i = 0; i < t.size(); i ++) {
            if (i == 0) {
                cout << t[i];
            }
            else {
                cout << " " << t[i];
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    vector<int> t;
    dfs(1, t);
    if (MAX) {
        cout << "Max Heap" << endl;
    }
    else if (MIN) {
        cout << "Min Heap" << endl;
    }
    else {
        cout << "Not Heap" << endl;
    }
    return 0;
}
