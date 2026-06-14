class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int x : nums) {
            st.insert(x);
        }
        int ans = 0;

        for (int x : nums) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (st.count(x+i)) {
                    count++;
                }
                else {
                    break;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
