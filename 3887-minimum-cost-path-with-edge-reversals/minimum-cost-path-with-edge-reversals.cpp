class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; // dist,node
        vector<int> dist(n, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int d = f.first;
            int u = f.second;
            if(u == n-1)break;

            for (auto nbr : adj[u]) {
                int w = nbr.second;
                int v = nbr.first;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return ( dist[n-1]==INT_MAX)?-1 : dist[n-1];
    }
};