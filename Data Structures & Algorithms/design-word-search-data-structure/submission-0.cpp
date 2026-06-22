class TreeNode {
public:
    // CHANGE 1: Vector holds unique_ptrs
    vector<unique_ptr<TreeNode>> children;
    bool endOfWord;

    TreeNode() {
        // Initialize vector of 26 null unique_ptrs
        // unique_ptr defaults to nullptr, so we just resize the vector
        children.resize(26); 
        endOfWord = false;
    }
};

class WordDictionary {
    // CHANGE 2: Root is a unique_ptr
    unique_ptr<TreeNode> root;

public:
    WordDictionary() {
        // CHANGE 3: Allocate with make_unique
        root = make_unique<TreeNode>();
    }
    
    void addWord(string word) {
        TreeNode* cur = root.get(); // Get raw pointer to observe/traverse
        for (char c : word) {
            int i = c - 'a';
            // Check if unique_ptr is null
            if (!cur->children[i]) { 
                cur->children[i] = make_unique<TreeNode>();
            }
            // Move raw pointer to the next child
            cur = cur->children[i].get(); 
        }
        cur->endOfWord = true; 
    }
    
    bool search(string word) {
        // Pass the raw pointer (.get()) to the recursive function
        return dfs(word, 0, root.get());
    }

private:
    // NOTE: The arguments stay as Raw Pointers (TreeNode*) because
    // this function just VISITS the node, it doesn't try to delete it.
    bool dfs(const string& word, int j, TreeNode* cur) {
        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            
            if (c == '.') {
                // Loop through the vector of unique_ptrs
                for (const auto& childPtr : cur->children) {
                    // Check if child exists and recurse using .get()
                    if (childPtr && dfs(word, i + 1, childPtr.get())) {
                        return true;
                    }
                }
                return false;
            } else {
                // Check if specific child exists
                if (!cur->children[c - 'a']) {
                    return false;
                }
                // Move raw pointer forward
                cur = cur->children[c - 'a'].get();
            }
        }
        return cur->endOfWord;
    }
};