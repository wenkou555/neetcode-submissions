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

private:
    int dfs(TreeNode* root, int& maxPath) {
        if (root == nullptr)
            return 0;

        int leftVal = max(0, dfs(root->left, maxPath));

        int rightVal = max(0, dfs(root->right, maxPath));

        maxPath = max(maxPath, root->val + leftVal + rightVal);
        return max(root->val + leftVal, root->val + rightVal);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};
