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
    bool isValidBST(TreeNode* root) {
        long long leftBound = LONG_MIN;
        long long rightBound = LONG_MAX;
        return dfs(root, leftBound, rightBound);
    }

    bool dfs(TreeNode* root, long long leftBound, long long rightBound) {
        if (root == nullptr)
            return true;
        
        if (root->val <= leftBound || root->val >= rightBound)
            return false;
        
        bool left = dfs(root->left, leftBound, root->val);
        bool right = dfs(root->right, root->val, rightBound);
        return left && right;
        
    }
};
