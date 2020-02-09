//
// Created by sgh on 2019-03-23.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> record;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()) {
                res.push_back(record[complement]);
                res.push_back(i);
                break;
            }
            record[nums[i]] = i;
        }
        return res;
    }
};