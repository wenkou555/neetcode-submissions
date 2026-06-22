class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        // 1. Build the pairs
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // 2. Sort by capital required (ascending)
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        // 3. The Execution Loop (Run at most K times)
        while (k--) {
            // Push all currently affordable projects into the heap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If we can't afford any more projects, break early
            if (maxHeap.empty()) {
                break;
            }

            // 4. THE FIX: Add the highest profit to our total accumulated capital
            w += maxHeap.top();
            maxHeap.pop();
        }

        // Return the final accumulated capital
        return w;
    }
};