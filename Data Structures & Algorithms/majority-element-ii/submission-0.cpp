class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int x : nums) {
            mp[x]++;
            if (mp[x] == target+1) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};