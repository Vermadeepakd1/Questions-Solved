class Solution {
public:
    bool bfs(vector<bool>&visited,unordered_map<int,vector<int>> &adj, int n, int node ){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        int nodes = 1;
        int total_degree = 0;

        while(!q.empty()){
            int root = q.front();
            q.pop();
            if (adj.count(root)) {
                total_degree += adj[root].size();
            }
            for(auto nbr : adj[root]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                    nodes++;
                }
            }
        }
        int edges = total_degree / 2;
        return edges == (nodes * (nodes-1))/2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>> adj;
        int cnt = 0;

        for(auto &ed : edges){
            int u = ed[0], v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                if(bfs(visited,adj,n, i))cnt++;
            }
        }
        return cnt;
    }
};