class Solution {
public:
    void dfs(unordered_set<string>&vis, double prod, double &ans, unordered_map<string, vector<pair<string, double>>> &adj, string src, string dest){
        if(vis.find(src) != vis.end())return ;

        vis.insert(src);

        if(src == dest){
            ans = prod;
            return;
        }

        for(auto &[nbr, cst] : adj[src]){
            dfs(vis,prod*cst, ans,adj,nbr,dest);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = values.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double cst = values[i];
            adj[u].push_back({v, cst});
            adj[v].push_back({u, 1.0 / cst});
        }
        vector<double>result;
        for (auto &q : queries) {
            string src = q[0];
            string dest = q[1];
            double prod = 1.0;
            double ans = -1.0;
            if (adj.find(src) != adj.end()) {
                unordered_set<string> vis;
                dfs(vis, prod, ans, adj, src, dest);
            }
            result.push_back(ans);
        }
        return result;
    }
};