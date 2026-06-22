class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        populateMap(tickets);
        vector<string> result;

        dfs("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flights;

    void populateMap(vector<vector<string>>& tickets) {
        if (tickets.size() == 0)
            return;

        for (const auto& ticket: tickets) {
            flights[ticket[0]].push(ticket[1]);
        }
    }


    void dfs(string airport, vector<string>& result) {
        
        // While there are still outgoing flights from this airport...
        while (!flights[airport].empty()) {
            
            string destination = flights[airport].top();
            flights[airport].pop();
            dfs(destination, result);
            
        }
        
        // We hit a dead end (no more outgoing flights).
        // Add this airport to the result list!
        result.push_back(airport);
    }
};
