//
// Created by fate on 2018/12/12.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int main() {
    string s;
    string t[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> s;
    int sum = 0;
    for(auto a : s) {
        sum += (a - '0');
    }
    vector<string> ans;
    do{
        ans.push_back(t[sum % 10]);
        sum /= 10;
    } while(sum);
    reverse(ans.begin(), ans.end());
    bool flag = true;
    for(auto s : ans) {
        if(flag) {
            cout << s;
            flag = false;
        } else {
            cout << " " << s;
        }
    }
    cout << endl;
    return 0;
}