class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        int strSize = s.length();
        vector<int> dp(strSize + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); i++) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }

            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[strSize];
    }
};
