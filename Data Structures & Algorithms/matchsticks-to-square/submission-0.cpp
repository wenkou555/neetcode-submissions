class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }

        if (sum == 0 || sum % 4 != 0)
            return false;

        sort(matchsticks.rbegin(), matchsticks.rend());
        int target = sum/4;

        return dfs(0, matchsticks, target, 0, 0, 0, 0);
    }

private:

    bool dfs(int i, vector<int>& matchsticks, int target, int top, int bottom, int left, int right) {
        if (top == target && bottom == target && left == target && right == target) {
            return true;
        }

        if (i >= matchsticks.size())
            return false;

        if (top > target || bottom > target || left > target || right > target)
            return false;
        
        int matchstick = matchsticks[i];
        if (matchstick > target)
            return false;

        return (dfs(i + 1, matchsticks, target, top + matchstick, bottom, left, right) || 
                dfs(i + 1, matchsticks, target, top, bottom + matchstick, left, right) || 
                dfs(i + 1, matchsticks, target, top, bottom, left + matchstick, right) || 
                dfs(i + 1, matchsticks, target, top, bottom, left, right + matchstick));
               
    }
};