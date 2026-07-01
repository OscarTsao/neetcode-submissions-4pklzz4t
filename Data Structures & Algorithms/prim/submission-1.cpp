class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> visited(n, false);
        minHeap.push({0, 0});

        int count = 0;
        int weight = 0;

        while (!minHeap.empty()) {
            auto [curWeight, u] = minHeap.top();
            minHeap.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            weight += curWeight;
            count++;
            if (count == n) break;

            for (const auto& [v, w] : adj[u]) {
                if (!visited[v]) minHeap.push({w, v});
            }
        }
        return (count==n)? weight:-1;
    }
};

