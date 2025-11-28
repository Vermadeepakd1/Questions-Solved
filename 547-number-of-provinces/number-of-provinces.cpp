class Solution {
    void dfs(unordered_map<int,vector<int>> &adj, vector<int> &visited, int node){
        visited[node] = true;

        for(int nbr : adj[node]){
            if(!visited[nbr] ){
                dfs(adj,visited,nbr);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        int n = isConnected.size();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int cnt= 0;
        vector<int> visited(n+1,0);

        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                dfs(adj,visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};