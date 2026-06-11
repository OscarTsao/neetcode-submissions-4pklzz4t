class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> count;
        for (int x : hand) {
            count[x]++;
        }

        for (auto& [card, freq] : count) {
            if (freq > 0) {
                int needed = freq;
                for (int i = 0; i < groupSize; i++) {
                    if (count[card+i] < needed) return false;
                    count[card+i] -= needed;
                }
            }
        }
        return true;
    }
};
