class Solution {
    
    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        
        for(int &nbr : adj[node]){
            if(!visited[nbr])
            dfs(nbr,adj,visited);
        }
    }
    
    bool isconnected(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        
        for(int i = 0; i<V; i++){
            if(adj[i].size() > 0){
                dfs(i,adj,visited);
                break;
            }
        }
        
        for(int i = 0; i<V; i++){
            if(adj[i].size() > 0 && !visited[i])return false;
        }
        
        return true;
    }
  public:
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        int odds = 0;
        
        if(!isconnected(V,adj))return false;
        
        for(int i = 0; i< V; i++){
            if(adj[i].size() & 1)odds++;
        }
        
        if(odds == 0)return 2;
        else if(odds == 2)return 1;
        return 0;
    }
};