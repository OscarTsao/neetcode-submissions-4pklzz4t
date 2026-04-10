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
    int index = 0;
    unordered_map<int, int> inorder_map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    

    for (int i = 0; i < inorder.size(); i++){
        inorder_map[inorder[i]] = i;
    }
    TreeNode* root = dfs(0, preorder.size() - 1, preorder);

    return root;
    }

private:
    TreeNode* dfs(int inStart, int inEnd, vector<int>& preorder){
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = inorder_map[rootVal];

        root->left = dfs(inStart, rootIdx - 1, preorder);
        root->right = dfs(rootIdx + 1, inEnd, preorder);

        return root;

    }
};
