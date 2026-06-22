class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto &s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // find '#'
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            res.push_back(word);
            i = j + 1 + len;
        }
        return res;
    }

};
