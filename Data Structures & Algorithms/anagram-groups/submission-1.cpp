class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for (auto &w : strs) {
            string key = w;
            sort(key.begin(), key.end());     // anagram signature
            buckets[key].push_back(w);        // keep original word
        }
        vector<vector<string>> res;
        res.reserve(buckets.size());
        for (auto &kv : buckets) res.push_back(move(kv.second));
        return res;
    }
};
