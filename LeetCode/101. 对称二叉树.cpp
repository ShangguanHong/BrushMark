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
        // iteratively
        bool isSymmetric(TreeNode* root) {
            if (root == NULL) {
                return true;
            }
            const int tt = -999999999;
            TreeNode* tmp = new TreeNode(tt);
            bool flag = true;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int cnt = q.size();
                vector<int> v;
                for (int i = 0; i < cnt; i ++) {
                    root = q.front();
                    q.pop();
                    v.push_back(root->val);
                    if (root->left != NULL) {
                        q.push(root->left);
                    } else if (root->val != tt){
                        q.push(tmp);
                    }
                    if (root->right != NULL) {
                        q.push(root->right);
                    } else if (root->val != tt){
                        q.push(tmp);
                    }
                }
                if (v.size() & 1 && !flag) {
                    return false;
                }
                flag = false;
                for (int i = 0; i < v.size() / 2; i ++) {
                    if (v[i] != v[v.size() - i - 1]) {
                        return false;
                    }
                }
            }
            return true;
        }
    };
};