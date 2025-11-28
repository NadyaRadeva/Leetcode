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
    void preorderTraversal(TreeNode* node, vector<int>& vec) {
        if(!node) {
            return;
        }

        vec.push_back(node->val);
        preorderTraversal(node->left, vec);
        preorderTraversal(node->right, vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        preorderTraversal(root, res);
        sort(res.begin(), res.end());
        return res[k-1];
    }
};
