class Solution {
    vector<int> parent,rank;
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    void unionset(int x , int y){
        if(find(x)==find(y))return;
        int xpar = parent[x];
        int ypar = parent[y];

        if(rank[xpar] > rank[ypar]){
            parent[ypar]=xpar;
        }else if(rank[xpar] < rank[ypar]){
            parent[xpar] = ypar;
        }else
        {
            rank[ypar]++;
            parent[xpar] = ypar;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.assign(n+1,-1);
        rank.assign(n+1,0);
        for(int i = 0; i<=n; i++)parent[i]=i;

        for(auto &vec : edges){
            int u = vec[0],v=vec[1];
            if(find(u)==find(v))return {u,v};
            else unionset(u,v);
        }
        return {};
    }
};