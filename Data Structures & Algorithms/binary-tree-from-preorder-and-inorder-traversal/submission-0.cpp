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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        return treeBuilder(preorder, preorderIndex, 0, inorder.size()-1);
    }

private:
    unordered_map<int, int> inorderMap;

    TreeNode* treeBuilder(vector<int>& preorder, int& preorderIndex, int leftBound, int rightBound) {
        if (rightBound < leftBound) {
            return nullptr;
        }

        int preorderValue = preorder[preorderIndex];
        TreeNode* node = new TreeNode(preorderValue);
        preorderIndex++;

        int split = inorderMap[preorderValue];

        node->left = treeBuilder(preorder, preorderIndex, leftBound, split - 1);
        node->right = treeBuilder(preorder, preorderIndex, split + 1, rightBound);


        return node; 

    }
};
