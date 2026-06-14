/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void dfs(TreeNode* root, vector<int>& dp, int k) {
        if (root == nullptr || dp.size() >= k) {
            return;
        }
        dfs(root->left, dp, k);
        if (dp.size() < k) {
            dp.push_back(root->val);
            dfs(root->right, dp, k);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> dp;
        dfs(root, dp, k);
        return dp[k-1];
    }
};
