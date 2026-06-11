class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cur = {0, 0, 0};

        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            cur[0] = max(cur[0], t[0]);
            cur[1] = max(cur[1], t[1]);
            cur[2] = max(cur[2], t[2]);
        }
        return cur == target;
    }
};
