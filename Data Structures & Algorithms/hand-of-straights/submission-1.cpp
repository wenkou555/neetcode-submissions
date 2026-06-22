class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> numFreqMap;
        for (int i = 0; i < hand.size(); i ++) {
            numFreqMap[hand[i]]++;
        }

        for (auto pair : numFreqMap) {
            int value = pair.first;
            int freq = pair.second;

            if (freq == 0)
                continue;
            
            for (int j = value; j < value + groupSize; j++) {
                if (numFreqMap.count(j) == 0)
                    return false;

                numFreqMap[j] -= freq;
                if (numFreqMap[j] < 0)
                    return false;
            }
            
        }

        return true;
    }
};
