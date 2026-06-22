class Solution {
public:
    string encode(vector<string>& strs) {
        string encodedStr;
        for(string str: strs) {
            encodedStr += to_string(str.size()) + "`";
            encodedStr += str;
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStr;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '`')
                j++;

            int strLen = std::stoi(s.substr(i, j-i));

            i = j + 1;
            decodedStr.push_back(s.substr(i, strLen));
            i = i + strLen;
        }

        return decodedStr;
    }
};
