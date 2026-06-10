class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode () {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    void insertWord (TrieNode* root, string word) {
        TrieNode* cur = root;
        for (char c: word) {
            int index = c - 'a';
            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->word = word;
    }

    void dfs (vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& results) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#') {
            return;
        }
        char c = board[row][col];
        int index = c - 'a';
        TrieNode* nextNode = node->children[index];
        
        if (nextNode == nullptr) return;

        if (nextNode->word != "") {
            results.push_back(nextNode->word);
            nextNode->word = "";
        } 

        board[row][col] = '#';

        dfs(board, row-1, col, nextNode, results);
        dfs(board, row+1, col, nextNode, results);
        dfs(board, row, col-1, nextNode, results);
        dfs(board, row, col+1, nextNode, results);

        board[row][col] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }

        int n = board.size();
        int m = board[0].size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
