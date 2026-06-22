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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        int height = dfs(root);

        return height >= 0;
        
    }

private:
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = dfs(root->left);
        if (leftHeight < 0)
            return -1;

        int rightHeight = dfs(root->right);
        if (rightHeight < 0)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
        
    }
};
