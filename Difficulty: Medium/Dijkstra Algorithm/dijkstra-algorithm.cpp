class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto i : edges){
            int u = i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // Code here
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        
        vector<int> result(V,INT_MAX);
        
        result[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(d > result[node])continue;
            
            for(auto &vec: adj[node]){
                int v = vec.first;
                int w = vec.second;
                
                if(d + w < result[v]){
                    result[v] = d+w;
                    pq.push({result[v],v});
                }
            }
        }
        
        return result;
    }
};