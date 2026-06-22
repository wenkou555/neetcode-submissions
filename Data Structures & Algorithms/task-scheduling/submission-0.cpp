class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxFreq = 0;
        for (char c: tasks) {
            freq[c - 'A']++;
            maxFreq = max(maxFreq, freq[c - 'A']);
        }

        int maxFreqCount = 0;
        for (int i: freq) {
            if (i == maxFreq)
                maxFreqCount++;
        }


        int calculation = (maxFreq - 1) * (n + 1) + maxFreqCount;

        return max((int)tasks.size(), calculation);


    }
};
