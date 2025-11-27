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
    void inorder(TreeNode* node, TreeNode*& prev, int& count, int& maxCount, vector<int>& res) {
        if(!node) {
            return;
        }

        inorder(node->left, prev, count, maxCount, res);

        if(prev && prev->val == node->val) {
            ++count;
        }
        else {
            count = 1;
        }

        if(count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(node->val);
        }
        else if(count == maxCount) {
            res.push_back(node->val);
        }

        prev = node;

        inorder(node->right, prev, count, maxCount, res);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxCount = 0;
        int count = 0;
        TreeNode* prev = nullptr;

        inorder(root, prev, count, maxCount, res);
        return res;
    }
};
