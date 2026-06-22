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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeImpl(root);
        return root;
        
    }

    void invertTreeImpl(TreeNode* root) {
        if (root == nullptr)
            return;
        
        if (root->left == nullptr and root->right == nullptr)
            return;

        TreeNode* prevLeft = root->left;
        root->left = root->right;
        root->right = prevLeft;
        invertTreeImpl(root->left);
        invertTreeImpl(root->right);
    }
};
