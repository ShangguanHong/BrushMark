//
// Created by sgh on 2019-03-23.
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
    // recursively
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        if (node1 == NULL || node2 == NULL) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return isSym(node1->left, node2->right) && isSym(node1->right, node2->left);
    }
};