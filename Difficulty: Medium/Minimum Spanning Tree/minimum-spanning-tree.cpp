class Solution {
    vector<int> parent, rank;
    
    int find(int x){
        if(x == parent[x])return x;
        return  parent[x] = find(parent[x]);
    }
    
    void unionset(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent)return ;
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent ] =x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent ] =y_parent;
        }else{
            parent[x_parent ] =y_parent;
            rank[y_parent]++;
        }
    }
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        auto comparator = [&](vector<int> &vec1, vector<int> &vec2){
            return vec1[2] < vec2[2];
        };
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i = 0; i<V; i++)parent[i]=i;
        
        sort(edges.begin(),edges.end(), comparator);
        
        int sum = 0;
        
        for(auto &temp : edges){
            int u = temp[0], v = temp[1],w =temp[2];
            
            int parent_u = find(u), parent_v = find(v);
            
            if(parent_u != parent_v){
                unionset(u,v);
                sum += w;
            }
        }
        
        return sum;
    }
};