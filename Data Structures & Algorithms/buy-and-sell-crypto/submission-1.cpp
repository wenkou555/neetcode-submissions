class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int profit = 0;

    for (int p : prices) {
        minPrice = min(minPrice, p);
        profit = max(profit, p - minPrice);
    }

    return profit;
}

};
