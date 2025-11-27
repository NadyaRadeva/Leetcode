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
    vector<string> result;

    string format(vector<int>& path) {
        string res = "";
        int n = path.size();
        for(int i = 0; i < n; ++i) {
            res += to_string(path[i]);
            if(i != n - 1) {
                res += "->";
            }
        }

        return res;
    }

    void dfs(TreeNode* node, vector<int>& path) {
        path.push_back(node->val);

        if(node->left) {
            dfs(node->left, path);
        }

        if(node->right) {
            dfs(node->right, path);
        }

        if(!node->left && !node->right) {
            result.push_back(format(path));
        }

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return result;
    }
};
