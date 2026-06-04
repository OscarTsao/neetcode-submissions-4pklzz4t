class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        int count = 0;
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        auto dfs = [&] (auto& self, int node) -> void {
            visited.insert(node);
            for (int neighbor: adj[node]) {
                if (!visited.count(neighbor)) self(self, neighbor);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                count++;
                dfs(dfs, i);
            }
        }

        return count;
    }
};
