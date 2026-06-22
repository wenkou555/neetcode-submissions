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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;

        if(isEqualTree(root, subRoot))
            return true;
        

        bool isSubTreeLeft = isSubtree(root->left, subRoot);
        bool isSubTreeRight = isSubtree(root->right, subRoot);

        return isSubTreeLeft || isSubTreeRight;
    }

private:
    bool isEqualTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        bool sameLeft = isEqualTree(p->left, q->left);
        bool sameRight = isEqualTree(p->right, q->right);

        
        return sameLeft && sameRight; 
        
    }
};
