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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        stack<TreeNode*> s;
        int res = 0;
        s.push(root);
        while (!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            int diameter = maxHeight(node->left) + maxHeight(node->right);
            res = max(res, diameter);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        return res;
        
    }
    int maxHeight(TreeNode* root){
        if (!root) return 0;
        else return max(maxHeight(root->left), maxHeight(root->right))+1;
    }
};
