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
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int res = 0;
        dfs(root, k, counter, res);
        return res;
        
    }

private:
    void dfs(TreeNode* node, int k, int& counter, int& res) {
        if (node == nullptr) {
            return;
        }

        if (k <= counter) {
            return;
        }

        dfs(node->left, k, counter, res);
        
        counter += 1;
        if (counter == k) {
            res = node->val;
            return;
        }


        dfs(node->right, k, counter, res);
    }
};
