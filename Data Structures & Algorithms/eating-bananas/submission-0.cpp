class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 0 || h <= 0)
            return -1;

        int left = 1;
        int right = 0;
        for (int i = 0; i < piles.size(); i++) {
            right = max(piles[i], right);
        } 

        while (left <= right) {
            int k = left + (right - left)/2;
            long long hoursNeeded = 0;
            for (int i = 0; i < piles.size(); i++) {
                hoursNeeded += (piles[i]/k);
                if (piles[i] % k != 0)
                    hoursNeeded += 1;
            }

            if (hoursNeeded > h) {
                left = k + 1;
            } else {
                right = k - 1;
            }
        }

        return left;
     
    }
};
