class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            minHeap.push(n); // Add the new number
    
            // 2. If we have too many, kick out the smallest
            if (minHeap.size() > k) {
                 minHeap.pop(); // Removes the smallest element instantly
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop(); // Removes the smallest element instantly
        }
        return minHeap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};
