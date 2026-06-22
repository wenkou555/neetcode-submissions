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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> container;
        traverseTree(root, container, 0);
        return container;
    }

private:
    void traverseTree(TreeNode* root, vector<vector<int>>& container, int level) {
        if (root == nullptr)
            return;
        
        if(level == container.size()) {
            container.push_back(vector<int>());
        }

        container[level].push_back(root->val);
        traverseTree(root->left, container, level + 1);
        traverseTree(root->right, container, level + 1);

    }
 
};

