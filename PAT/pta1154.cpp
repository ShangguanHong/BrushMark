//
// Created by fate on 2018/12/12.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> p[m];
    for(int i = 0; i < m; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    int k;
    cin >> k;
    while(k --) {
        int aa[n];
        set<int> s;
        for(int i = 0; i < n; i ++) {
            cin >> aa[i];
            s.insert(aa[i]);
        }
        bool flag = false;
        for(int i = 0; i < m; i ++) {
            if(aa[p[i].first] == aa[p[i].second]) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "No" << endl;
        } else {
            cout << s.size() << "-coloring" << endl;
        }
    }
    return 0;
}