class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto top = pq.top();
            int d = top.first;
            int node = top.second;
            pq.pop();

            for (auto i : adj[node]) {
                int v = i.first;

                int w = i.second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxWait = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            maxWait = max(maxWait, dist[i]);
        }
        return maxWait;
    }
};