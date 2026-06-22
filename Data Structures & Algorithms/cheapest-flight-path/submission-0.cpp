class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            
            for (auto& flight: flights) {
                int from = flight[0];
                int to = flight[1];
                int amount = flight[2];

                if (prices[from] == INT_MAX)
                    continue;

                if (prices[from] + amount < temp[to])
                    temp[to] = prices[from] + amount;
            }

            prices = temp;
        }


        if (prices[dst] != INT_MAX)
            return prices[dst];
        else
            return -1;
        
    }
};
