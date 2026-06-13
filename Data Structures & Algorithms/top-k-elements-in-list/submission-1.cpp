class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        vector<pair<int, int>> freq;
        for (auto& p : mp) {
            freq.push_back({p.second, p.first});
        }
        sort(freq.begin(), freq.end());
        vector<int> ans;
        int n = freq.size();    
        for (int i = n-1; i >= n-k; i--) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
