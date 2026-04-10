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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> iterates;

        iterates.push({p, q});

        while(!iterates.empty()){
            for (int i = iterates.size(); i > 0; i--){
                auto [node1, node2] = iterates.front();
                iterates.pop();


                if (node1 == nullptr && node2 == nullptr) continue;
                else if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) return false;

                iterates.push({node1->left, node2->left});
                iterates.push({node1->right, node2->right});
            }
        }
        return true;
    }
};
