class TreeNode {
public:
    vector<unique_ptr<TreeNode>> children;
    string word;

    TreeNode() {
        children.resize(26); 
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        int m = board.size();
        if (m == 0)
            return result;

        int n = board[0].size();
        if (n == 0)
            return result;

        unique_ptr<TreeNode> root = make_unique<TreeNode>();
        for (string word: words) {
            addWord(word, root.get());
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, result, root.get(), i, j);
            }
        }
        return result;  
    }

private:
    void addWord(string word, TreeNode* root) {
        TreeNode* cur = root; // Get raw pointer to observe/traverse
        for (char c : word) {
            int i = c - 'a';
            // Check if unique_ptr is null
            if (!cur->children[i]) { 
                cur->children[i] = make_unique<TreeNode>();
            }
            // Move raw pointer to the next child
            cur = cur->children[i].get(); 
        }
        cur->word = word; 
    }

    void dfs(vector<vector<char>>& board, vector<string>& result, TreeNode* cur, int m, int n) {
        if (m < 0 || n < 0 || m >= board.size() || n >= board[0].size())
            return;
        
        if (board[m][n] == '#')
            return;

        char curChar = board[m][n];
        if (not cur->children[curChar - 'a'])
            return;

        TreeNode* nextNode = cur->children[curChar - 'a'].get();
        if (nextNode->word != "") {
            result.push_back(nextNode->word);
            nextNode->word = "";
        }
        

        board[m][n] = '#';
        dfs(board, result, nextNode, m + 1, n);
        dfs(board, result, nextNode, m, n + 1);
        dfs(board, result, nextNode, m - 1, n);
        dfs(board, result, nextNode, m, n - 1);
        board[m][n] = curChar;
    }
    
};




