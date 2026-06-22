class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (amount == 0 || n == 0)
            return 1;

        vector<int> wayCounter(amount + 1, 0);
        wayCounter[0] = 1;

        for (int coin: coins) {
            for (int i = 1; i <= amount; i++) {
                if (coin > i)
                    continue;

                wayCounter[i] += wayCounter[i - coin];
            }
        }

        return wayCounter[amount];
        
    }
};
