//
// Created by sgh on 2019-03-24.
//

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int a[100000], ans = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < J.length(); i ++) {
            a[J[i] - '\0'] = 1;
        }
        for(int i = 0; i < S.length(); i ++) {
            if(a[S[i] - '\0'] == 1) {
                ans ++;
            }
        }
        return ans;
    }
};