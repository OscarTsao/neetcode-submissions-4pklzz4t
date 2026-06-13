class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) {
            return n;
        }

        unordered_set<int> st;
        int ans = 0;
        for (int x : nums) {
            st.insert(x);
        }
        int m = st.size();
        for (int x : st) {
            for (int i = 0; i < st.size(); i++) {
                if (st.count(x+i)) {
                    ans = max(ans, i+1);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};
