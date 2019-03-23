//
// Created by sgh on 2019-03-23.
//

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> record;
        vector<string> res;
        if (s.size() < 10) return res;
        for (int i = 0; i <= s.size() - 10; i ++) {
            string str = s.substr(i, 10);
            if (++record[str] == 2) {
                res.push_back(str);
            }
        }
        return res;
    }
};