class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int x: nums) {
            sum += x;

            if (mp.count(sum-k)) count += mp[sum-k];
            if (mp.count(sum)) mp[sum]++;
            else mp[sum] = 1;
        }
        return count;
    }
};