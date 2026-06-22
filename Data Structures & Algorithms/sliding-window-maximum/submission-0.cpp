class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> cache;
        vector<int> maxElem;
        for (int i = 0; i < nums.size(); i++) {
            while (not cache.empty() and nums[cache.back()] < nums[i])
                cache.pop_back();
            cache.push_back(i);

            if (i + 1 >= k)
                {
                    if (cache.front() < i + 1 - k) {
                        cache.pop_front();
                    }
                    maxElem.push_back(nums[cache.front()]);
                }
        }
        return maxElem;
    }
};
