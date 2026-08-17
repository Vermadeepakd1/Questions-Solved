class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& time, vector<int>& low,
             vector<vector<int>>& bridges) {
        vis[node] = 1;
        time[node] = timer;
        low[node] = timer;
        timer++;

        for (auto nbr : adj[node]) {
            if (nbr != parent) {
                if (vis[nbr] == 0) {
                    dfs(nbr, node, vis, adj, time, low, bridges);
                    low[node] = min(low[node], low[nbr]);
                    if (low[nbr] > time[node]) {
                        bridges.push_back({nbr, node});
                    }
                } else {
                    low[node] = min(low[node], low[nbr]);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto& vec : connections) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n), low(n);
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, time, low, bridges);

        return bridges;
    }
};