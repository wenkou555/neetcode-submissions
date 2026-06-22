class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // The road from km 0 to km 1000
        vector<int> road(1001, 0);
        
        // 1. Stamp the road with passenger changes
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            road[from] += numPassengers; // Passengers get in
            road[to] -= numPassengers;   // Passengers get out
        }
        
        // 2. Drive the car down the road
        int current_passengers = 0;
        for (int i = 0; i < 1001; i++) {
            current_passengers += road[i];
            
            // If we ever exceed capacity, we fail
            if (current_passengers > capacity) {
                return false;
            }
        }
        
        return true; // We survived the trip!
    }
};