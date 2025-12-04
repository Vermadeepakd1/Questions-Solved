class Solution {
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x)return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void unionset(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent)return;
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
  public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        rank.resize(V);
        parent.resize(V);
        
        for(int i = 0; i<V; i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        for(int u = 0; u<V; u++){
            for(int &v: adj[u]){
                if(u<v){
                    if(find(u) == find(v)){
                        return true;
                    }else{
                        unionset(u,v);
                    }
                }
            }
        }
        return false;
    }
};