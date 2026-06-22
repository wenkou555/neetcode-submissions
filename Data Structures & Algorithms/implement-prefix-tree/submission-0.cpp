class TreeNode {
public :
    vector<unique_ptr<TreeNode>> children;
    bool endOfWord;

    TreeNode() {
        children.resize(26);
        endOfWord = false;
    }
};


class PrefixTree {
    unique_ptr<TreeNode> root;

public:
    PrefixTree() {
        root = make_unique<TreeNode>();
    }
    
    void insert(string word) {
        TreeNode* cur = root.get();
        for (char c: word) {
            int i = c - 'a';
            if (!cur->children[i]) {
                cur->children[i] = make_unique<TreeNode>();
            }
            cur = cur->children[i].get();
        }
        cur->endOfWord = true; 
        
    }
    
    bool search(string word) {
        TreeNode* cur = root.get();
        for (char c: word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i].get();
        }

        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root.get();
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i].get();
        }
        
        return true;
        
    }
};
