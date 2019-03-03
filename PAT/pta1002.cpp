//
// Created by fate on 2018/12/12.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int, double, greater<> > nums;
    int k, a;
    double b;
    cin >> k;
    while(k --) {
        cin >> a >> b;
        nums[a] += b;
    }
    cin >> k;
    while(k --) {
        cin >> a >> b;
        nums[a] += b;
        if(nums[a] == 0.0) {
            nums.erase(a);
        }
    }
    cout << nums.size();
    if(!nums.empty()) {
        for(auto &num : nums) {
            printf(" %d %.1lf", num.first, num.second);
        }
    }
}