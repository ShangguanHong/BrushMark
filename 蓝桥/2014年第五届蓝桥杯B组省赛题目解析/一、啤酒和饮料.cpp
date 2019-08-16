//
// Created by fate on 2019/3/3.
//

/*
啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。
我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
 */

#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 0; i < 36; i ++) {
        for(int j = i + 1; j < 44; j ++) {
            if(23 * i + 19 * j == 823) {
                cout << "买了啤酒" << i << "罐, 买了饮料" << j << "罐" << endl;
                return 0;
            }
        }
    }
    return 0;
}