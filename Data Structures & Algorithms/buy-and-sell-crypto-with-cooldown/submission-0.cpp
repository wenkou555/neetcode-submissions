class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int held = -prices[0];
        int sold = 0;
        int reset = 0;

        for (int i = 1; i < prices.size(); i ++) {
            int tempHeld = max(held, reset - prices[i]);
            int tempSold = held + prices[i];
            int tempReset = max(reset, sold);
            held = tempHeld;
            sold = tempSold;
            reset = tempReset;
        }

        return max(sold, reset);
        
    }
};
