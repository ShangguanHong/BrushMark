//
// Created by sgh on 2019-03-21.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == NULL) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> tmp;
            for (int i = 0; i < cnt; i ++) {
                root = q.front();
                q.pop();
                tmp.push_back(root->val);
                if (root->left != NULL) {
                    q.push(root->left);
                }
                if (root->right != NULL) {
                    q.push(root->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};