//
// Created by sgh on 2019-03-24.
//

class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};