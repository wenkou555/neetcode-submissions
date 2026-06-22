class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // 1. Augment tasks with original indices using array<int, 3>
        vector<array<int, 3>> extTasks(n);
        for (int i = 0; i < n; ++i) {
            extTasks[i] = {tasks[i][0], tasks[i][1], i};
        }
        
        // 2. Sort by enqueue time
        sort(extTasks.begin(), extTasks.end());
        
        // Min-Heap: {processingTime, original_index}
        using pi = pair<int, int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        vector<int> result;
        long long cur_time = 0; // Prevent integer overflow
        int i = 0;
        
        // 3. The Main Simulation Loop
        while (i < n || !pq.empty()) {
            // Fast-forward time if the CPU is idle
            if (pq.empty() && cur_time < extTasks[i][0]) {
                cur_time = extTasks[i][0];
            }
            
            // Push all currently available tasks into the Min-Heap
            while (i < n && extTasks[i][0] <= cur_time) {
                pq.push({extTasks[i][1], extTasks[i][2]});
                i++;
            }
            
            // Process the best task
            auto [processTime, originalIdx] = pq.top();
            pq.pop();
            
            cur_time += processTime;
            result.push_back(originalIdx);
        }
        
        return result;
    }
};