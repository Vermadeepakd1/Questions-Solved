// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,INT_MAX);
        
        dist[src] = 0;
        
        for(int i = 0; i<V-1; i++){
            for(auto &vec : edges){
                int u = vec[0], v = vec[1], w = vec[2];
                
                if(dist[u]!= INT_MAX && dist[u] + w <dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        for(auto &vec : edges){
                int u = vec[0], v = vec[1], w = vec[2];
                
                if(dist[u]!= INT_MAX && dist[u] + w <dist[v]){
                    return {-1};
                }
        }
        
        for(int i = 0; i<V; i++){
            if(dist[i] == INT_MAX)dist[i] = 1e8;
        }
        
        return dist;
        
    }
};
