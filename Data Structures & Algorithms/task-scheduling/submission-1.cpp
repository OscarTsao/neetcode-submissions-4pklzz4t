class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char c : tasks) {
            counts[c-'A']++;
        }

        priority_queue<int> maxHeap;
        for (int count : counts) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }
        
        queue<pair<int, int>> waitQ;
        int time = 0;

        while (!maxHeap.empty() || !waitQ.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int currentTaskCount = maxHeap.top();
                maxHeap.pop();
                currentTaskCount--;

                if (currentTaskCount > 0) {
                    waitQ.push({currentTaskCount, time+n});
                }
            }

            if (!waitQ.empty() && waitQ.front().second == time) {
                maxHeap.push(waitQ.front().first);
                waitQ.pop();
            }
        }
        return time;
    }
};
