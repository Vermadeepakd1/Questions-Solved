class Solution {
    bool possible(unordered_map<int,list<int>> &adj,vector<int> &color, int idx, int i){
        for(auto n : adj[idx]){
            if(color[n] == i)return false;
        }
        return true;
    }
    
    bool canColor(unordered_map<int,list<int>> &adj, int m, int v, int idx,vector<int> &color){
        if(idx == v) return true;
        
        for(int i = 1; i <= m; i++) {
            if(possible(adj, color, idx, i)) {
                color[idx] = i;
                if (canColor(adj, m, v, idx + 1, color)) return true;
                color[idx] = 0;  // backtrack here
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> color(v,0);
        
        unordered_map<int,list<int>> adj;
        
        for(auto e: edges){
            int ue = e[0];
            int ve = e[1];
            
            adj[ue].push_back(ve);
            adj[ve].push_back(ue);
        }
        
        return canColor(adj,m,v,0,color);
        
    }
};