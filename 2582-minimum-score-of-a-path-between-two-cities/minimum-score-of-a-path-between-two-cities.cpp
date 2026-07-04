class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        queue<int> q;
        q.push(1);
        q.push(n);

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &vec : roads){
            int u = vec[0], v = vec[1],d = vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        int ans = INT_MAX;
        vector<bool> visited(n+1,false);
        visited[n] = true;
        visited[1] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &[nbr,d] : adj[node]){
                ans = min(ans,d);
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        return ans;
    }
};