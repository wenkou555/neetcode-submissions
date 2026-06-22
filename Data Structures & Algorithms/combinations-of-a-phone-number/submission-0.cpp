class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res = {};
        if (digits.empty())
            return res;

        string substr = "";

        getCombinations(digits, 0, substr, res);
        return res;
    }   

private:
    const vector<string> phoneStr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void getCombinations(string& digits, int index, string& substr, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(substr);
            return;
        }

        int number = digits[index] - '0';
        string chars = phoneStr[number];

        for (char c : chars) {
            substr.push_back(c);
            getCombinations(digits, index + 1, substr, res);
            substr.pop_back();
        }

    }
};
