//
// Created by sgh on 2019-03-20.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        if (root == NULL) {
            return res;
        }
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            res.push_back(root->val);
            if (root->right != NULL) {
                st.push(root->right);
            }
            if (root->left != NULL) {
                st.push(root->left);
            }
        }
        return res;
    }
};