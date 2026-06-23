class Solution {
private: 
    bool backtrack(vector<int>& nums, vector<bool>& visited, int target, int currentSum, int startIndex, int k) {
        if (k == 1) return true;
        if (currentSum == target) return backtrack(nums, visited, target, 0, 0, k-1);

        int n = nums.size();
        for (int i = startIndex; i < n; i++) {
            if (visited[i] || currentSum + nums[i] > target) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = true;

            if (backtrack(nums, visited, target, currentSum+nums[i], i+1, k)) return true;

            visited[i] = false;
            if (currentSum == 0) return false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % k != 0) return false;
        int target = sum / k;
        int n = nums.size();

        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<bool> visited(n, false);
        return backtrack(nums, visited, target, 0, 0, k);
    }
};