class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
     int sum = 0;
     int n = nums.size();

     auto dfs = [&] (auto& self, int start, int cur_xor) -> void {
        sum += cur_xor;
        for (int i = start; i < n; i++) {
            cur_xor ^= nums[i];
            self(self, i+1, cur_xor);
            cur_xor ^= nums[i];
        }
     };
     dfs(dfs, 0, 0);
     return sum;
    }
};