class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numSeen;
        while (n != 1 && numSeen.find(n) == numSeen.end()) {
            numSeen.insert(n);
            int sum = 0;
            while (n > 0) {
                int rest = n%10;
                sum += rest * rest;
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};
