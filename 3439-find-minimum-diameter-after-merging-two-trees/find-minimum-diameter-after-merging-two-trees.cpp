class Solution {
    pair<int, int> bfs(unordered_map<int, vector<int>>& adj, int src) {
        queue<int> q;
        q.push(src);

        unordered_map<int, bool> visited;
        visited[src] = true;

        int lastnode = src, distance = -1;

        while (!q.empty()) {
            int x = q.size();
            distance++;
            lastnode = q.front();
            for (int i = 0; i < x; i++) {
                int nd = q.front();
                q.pop();
                for (auto nbr : adj[nd]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }

        return {lastnode, distance};
    }

    int findDiameter(unordered_map<int, vector<int>>& adj) {
        auto [farthest, dist] = bfs(adj, 0);
        auto [other, diameter] = bfs(adj, farthest);

        return diameter;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1, adj2;

        for (auto& vec : edges1) {
            int u = vec[0];
            int v = vec[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (auto& vec : edges2) {
            int u = vec[0];
            int v = vec[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int newmax = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        int ans = max({d1, d2, newmax});

        return ans;
    }
};