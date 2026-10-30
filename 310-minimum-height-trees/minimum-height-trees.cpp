class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        unordered_map<int, vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++, degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        while (n > 2) {
            int x = q.size();
            n -= x;

            while (x--) {
                int t = q.front();
                q.pop();

                for (auto nbr : adj[t]) {
                    degree[nbr]--;
                    if (degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};