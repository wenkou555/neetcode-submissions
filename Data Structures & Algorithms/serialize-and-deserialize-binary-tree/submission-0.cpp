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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == nullptr) {
            return "N,";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        int startIndex = 0;
        return buildTree(data, startIndex);
    }

private:

    TreeNode* buildTree(string& data, int& index) {
        if (index >= data.size() ) {
           return nullptr;
        }

        int commaPos = index;
        while (commaPos <= data.size() - 1 && data[commaPos] != ',') {
            commaPos++;
        }
        string subString = data.substr(index, commaPos - index);
        index = commaPos + 1;

        if (subString == "N")
            return nullptr;

        int value = stoi(subString);
        TreeNode* node = new TreeNode(value);

        if (node == nullptr)
            return nullptr;

        node->left = buildTree(data, index);
        node->right = buildTree(data, index);
        return node;
    }
};
