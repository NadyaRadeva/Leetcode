/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return dfs(root, false);
    }

    int dfs(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }

        if (isLeft && !node->left && !node->right) {
            return node->val;
        }

        return dfs(node->left, true) + dfs(node->right, false);
    }
};
