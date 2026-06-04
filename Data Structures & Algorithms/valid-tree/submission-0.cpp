class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        
        unordered_set<int> visited;
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        auto dfs = [&](auto& self, int node) -> void {
            visited.insert(node);
            
            for (int neighbor : adj[node]) {
                // 關鍵修正：必須確認鄰居尚未拜訪過，才繼續深入！
                if (visited.find(neighbor) == visited.end()) {
                    self(self, neighbor);
                }
            }
        };

        dfs(dfs, 0);
        return (visited.size() == n);
    }
};
