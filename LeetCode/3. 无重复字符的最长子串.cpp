//
// Created by sgh on 2019-03-23.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;
        map<char, int> record;
        for (int i = 0; i < s.size(); i ++) {
            if (record.find(s[i]) != record.end() && record[s[i]] >= left) {
                res = max(res, i - left);
                left = record[s[i]] + 1;
            } else if (i == s.size() - 1) {
                res = max(res, i - left + 1);
            }
            record[s[i]] = i;
        }
        return res;
    }
};