class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (const char c : tasks) {
            int index = c - 'A';
            freq[index]++;
            maxFreq = max(maxFreq, freq[index]);
        }

        int maxFreqCount = 0;

        for (int x : freq) {
            if (x == maxFreq) {
                maxFreqCount++;
            }
        }

        int chunks = maxFreq - 1;
        int chunkLength = n + 1;
        int calculatedLength = chunks * chunkLength + maxFreqCount;

        return max((int) tasks.size(), calculatedLength);
    }
};
