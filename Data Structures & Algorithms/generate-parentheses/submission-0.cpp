class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        string parentheses= "";
        backtrack(0, 0, n, parentheses, res);
        return res;
    }

private:

    void backtrack(int open, int close, int n, string& parentheses, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(parentheses);
            return;
        }

        if (open < n) {
            parentheses += "(";
            backtrack(open + 1, close, n, parentheses, res);
            parentheses.pop_back();
        }
        if (close < open ) {
            parentheses += ")";
            backtrack(open, close + 1, n, parentheses, res);
            parentheses.pop_back();
        }
    }
};
