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

class Codec {
private: 
    TreeNode* buildTree(queue<string>& q) {
        if (q.front() == "X") {
            q.pop();
            return nullptr;
        }
        else {
            TreeNode* node = new TreeNode(stoi(q.front()));
            q.pop();
            node->left = buildTree(q);
            node->right = buildTree(q);
            return node;
        }
        
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "X";

        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        queue<string> q;

        while (getline(ss, token, ',')) {
            q.push(token);
        }

        return buildTree(q);
    }
};
