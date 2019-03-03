//
// Created by fate on 2018/12/12.
//

#include <bits/stdc++.h>
using namespace std;
string unlockId, lockId, inTime = "23:59:59", outTime = "00:00:00";
int m;

int main() {
    cin >> m;
    string id, in, out;
    while(m --) {
        cin >> id >> in >> out;
        if(in < inTime) {
            inTime = in;
            unlockId = id;
        }
        if(out > outTime) {
            outTime = out;
            lockId = id;
        }
    }
    cout << unlockId << " " << lockId << endl;
    return 0;
}