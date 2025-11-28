class Solution {
    int count = 0;

    long long dfs(unordered_map<int, vector<int>>& adj, int node, int parent,
            vector<int>& values, int k) {
        long long sum = values[node];
        for (int nbr : adj[node]) {
            if (nbr != parent)
                sum += dfs(adj, nbr, node, values, k);
        }
        if (sum % k == 0) {
            count++;
            return 0;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        unordered_map<int, vector<int>> adj;

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj, 0, -1, values, k);
        return count;
    }
};