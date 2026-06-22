class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinTracker(amount + 1, amount + 1);
        coinTracker[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin: coins) {
                if (coin <= i) {
                    coinTracker[i] = min(coinTracker[i], coinTracker[i - coin] + 1);
                }
            }
        }

        return coinTracker[amount] == amount + 1 ? -1 : coinTracker[amount];
    }
};
