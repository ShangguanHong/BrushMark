//
// Created by sgh on 2019-03-23.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) {
            return res;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int complement = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == complement) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l]) l ++;
                    while (l < r && nums[r - 1] == nums[r]) r --;
                    l ++;
                    r --;
                } else if (nums[l] + nums[r] > complement) {
                    r --;
                } else {
                    l ++;
                }
            }
        }
        return res;
    }
};