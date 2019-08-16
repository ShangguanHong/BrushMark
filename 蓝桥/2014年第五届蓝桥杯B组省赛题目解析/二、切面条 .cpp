//
// Created by fate on 2019/3/3.
//
/*
一根高筋拉面，中间切一刀，可以得到2根面条。

如果先对折1次，中间切一刀，可以得到3根面条。

如果连续对折2次，中间切一刀，可以得到5根面条。

那么，连续对折10次，中间切一刀，会得到多少面条呢？
*/

#include <bits/stdc++.h>
using namespace std;
int ans[12];
int main() {
    ans[0] = 2;
    for(int i = 1; i < 11; i ++) {
        ans[i] = 2 * ans[i - 1] - 1;
    }
    cout << ans[10] << endl;
    return 0;
}
