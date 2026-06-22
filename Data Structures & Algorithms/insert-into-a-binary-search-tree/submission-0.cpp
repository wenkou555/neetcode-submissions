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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: We found an empty spot! Create the new node here.
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        // If the value is smaller, it belongs somewhere in the left subtree
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } 
        // If the value is larger, it belongs somewhere in the right subtree
        else {
            root->right = insertIntoBST(root->right, val);
        }
        
        // Return the unchanged root node
        return root;
    }
};