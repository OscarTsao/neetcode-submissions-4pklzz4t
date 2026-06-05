class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i< n; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                int index = (i+j) % n;
                cur = cur + gas[index] - cost[index];
                if (cur < 0) break;
            }
            if (cur >= 0) return i;
        }
        return -1;
    }
};
