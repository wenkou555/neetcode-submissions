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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> contrainer;
        rightSideImpl(root, contrainer, 0);
        return contrainer;
    }

private:
    void rightSideImpl(TreeNode* node, vector<int>& container, int level) {
        if (node == nullptr)
            return;

        if (container.size() == level) {
            container.push_back(node->val);
        }

        rightSideImpl(node->right, container, level + 1);
        rightSideImpl(node->left, container, level + 1);
    }
};
