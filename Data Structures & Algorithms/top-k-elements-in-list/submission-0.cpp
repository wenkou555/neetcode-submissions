class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        // Map: Number -> Frequency
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Create buckets where Index = Frequency
        // The maximum frequency possible is nums.size(), so we need size + 1
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        // Step 3: Iterate buckets from end (highest freq) to beginning
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            // If bucket is not empty, add its contents to result
            for (int num : buckets[i]) {
                result.push_back(num);
                
                // Once we have k elements, we are done
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
