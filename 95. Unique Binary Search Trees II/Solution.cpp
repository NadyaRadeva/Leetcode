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
    vector<TreeNode*> builder(int start, int end) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (int rootVal = start; rootVal <= end; ++rootVal) {
            vector<TreeNode*> leftTrees = builder(start, rootVal - 1);
            vector<TreeNode*> rightTrees = builder(rootVal + 1, end);

            for (int i = 0; i < (int)leftTrees.size(); ++i) {
                for (int j = 0; j < (int)rightTrees.size(); ++j) {

                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];

                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        
        return builder(1, n);
    }
};
