//
// Created by sgh on 2019-03-24.
//

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        int res = 0;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < B.size(); j ++) {
                record[A[i] + B[j]] ++;
            }
        }
        for (int i = 0; i < C.size(); i ++) {
            for (int j = 0; j < D.size(); j ++) {
                res += record[-(C[i] + D[j])];
            }
        }
        return res;
    }
};