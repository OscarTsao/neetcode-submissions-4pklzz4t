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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> res;
     queue<TreeNode*> traversal;

     if (!root) return res;

     traversal.push(root);

     while (!traversal.empty()){
        vector<int> level;
        int n = traversal.size();

        for (int i = 0; i < n; i++){
            TreeNode* cur = traversal.front();
            traversal.pop();
            if (cur){
                level.push_back(cur->val);
                traversal.push(cur->left);
                traversal.push(cur->right);
            }   
        }
        if (level.empty()) break;
        res.push_back(level); 
     }   
     return res;
    }
};
