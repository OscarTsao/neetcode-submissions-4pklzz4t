class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while (!minHeap.empty()) {
            int time = minHeap.top().first;
            int u = minHeap.top().second;
            minHeap.pop();

            if (time > dist[u]) {
                continue;
            }
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;
                if (dist[v] > dist[u]+cost) {
                    dist[v] = dist[u]+cost;
                    minHeap.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
