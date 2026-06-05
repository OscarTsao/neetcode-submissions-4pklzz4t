class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x: nums) {
            sum += x;
        }
        if (sum % 2) return false;
        sum /= 2;

        unordered_set<int> st;
        st.insert(0);

        for (int x: nums) {
            unordered_set<int> dp;
            for (int y: st) {
                if (y+x == sum) return true;
                dp.insert(y);
                dp.insert(y+x);
            }
            st = dp;
        }
        return false;
    }
};
