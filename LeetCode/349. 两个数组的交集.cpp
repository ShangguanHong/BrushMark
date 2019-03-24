//
// Created by sgh on 2019-03-24.
//

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i ++) {
            if(find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() &&
               find(ans.begin(), ans.end(), nums1[i]) == ans.end()) {
                ans.push_back(nums1[i]);
            }
        }

        return ans;
    }
};