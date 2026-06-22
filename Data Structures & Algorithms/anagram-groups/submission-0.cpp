class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagram_map;
        for (string word: strs) {
            string sorted_str = word;
            std::sort(sorted_str.begin(), sorted_str.end());
            anagram_map[sorted_str].push_back(word);
        }

        vector<vector<string>> return_vector;
        for (const auto& [key, value] : anagram_map) {
            return_vector.push_back(value);
        }

        return return_vector;
    }
};
