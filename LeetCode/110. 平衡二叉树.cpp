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
    bool isBalance = true;
    bool isBalanced(TreeNode* root) {
        getDepth(root);
        return isBalance;
    }
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int x = getDepth(root->left);
        int y = getDepth(root->right);
        if (abs(x - y) > 1) {
            isBalance = false;
        }
        return max(x, y) + a1;
    }
};