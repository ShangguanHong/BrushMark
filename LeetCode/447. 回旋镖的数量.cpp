//
// Created by sgh on 2019-03-24.
//

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i ++) {
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); j ++) {
                if (i == j) continue;
                record[dir(points[i], points[j])] ++;
            }
            for (auto iter : record) {
                res += iter.second * (iter.second - 1);
            }
        }
        return res;
    }

    int dir(pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
};