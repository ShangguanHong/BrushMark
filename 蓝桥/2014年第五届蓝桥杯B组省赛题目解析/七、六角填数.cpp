//
// Created by fate on 2019/3/6.
//

/*

如图所示六角形中，填入1~12的数字。

使得每条直线上的数字之和都相同。

图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？
*/

#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int num[13];
    int line[6];
    for(int i = 1; i < 13; i ++) {
        num[i] = i;
    }
    do{
        if(num[1] != 1 || num[2] != 8 || num[12] != 3) {
            continue;
        }
        line[0] = 1 + num[3] + num[6] + num[8];
        line[1] = 1 + num[4] + num[7] + num[11];
        line[2] = num[8] + num[9] + num[10] + num[11];
        line[3] = 8 + num[6] + num[9] + 3;
        line[4] = num[5] + num[7] + num[10] + 3;
        line[5] = num[2] + num[3] + num[4] + num[5];
        bool flag = true;
        for(int i = 0; i < 5; i ++) {
            if(line[i] != line[i + 1]){
                flag= false;
                break;
            }
        }
        if(flag) {
            cout << num[6] << endl;
            return 0;
        }
    } while(next_permutation(num + 1, num + 13));
    return 0;
}
