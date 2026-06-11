class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;
        for (int x : nums) {
            st.insert(x);
            ans = max(ans, x);
        }
        ans += 1;
        for (int i = 1; i < ans; i++) {
            if (!st.count(i)) {
                return i;
            }
        }
        return ans;
        
    }
};