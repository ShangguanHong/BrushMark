//
// Created by fate on 2019/3/3.
//

/*
话说大诗人李白，一生好饮。幸好他从不开车。

一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：

 无事街上走，提壶去打酒。
    逢店加一倍，遇花喝一斗。

    这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。

    请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。
    像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）
*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void dfs(int store, int flower, int wine) {
    if(store == 0 && flower == 0 && wine == 0) {
        cnt ++;
        return ;
    }
    if((store != 0 || flower != 0) && wine <= 0) {
        return ;
    }
    if(store != 0) {
        dfs(store - 1, flower, wine * 2);
    }
    if(flower != 0) {
        dfs(store, flower - 1, wine - 1);
    }
}

int main() {
    dfs(5, 10, 2);
    cout << cnt << endl;
    return 0;
}