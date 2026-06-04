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
public:
    int goodNodes(TreeNode* root) {
        int count = 0;

        auto dfs = [&] (auto& self, TreeNode* root, int prev) -> int {
            if (root == nullptr) return 0;

            if (prev <= root->val) {
                count++;
                prev = root->val;
            }
            self(self, root->left, prev);
            self(self, root->right, prev);
            return prev;
        };
        dfs(dfs, root, root->val);
        return count;
    }
};
