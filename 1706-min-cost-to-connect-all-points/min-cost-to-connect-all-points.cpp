class Solution {
    vector<int> parent,rank;

    int find(int x){
        if(x == parent[x])return x;

        return parent[x] = find(parent[x]);
    }

    void unionset(int x, int y){
        int xparent =parent[x];
        int yparent = parent[y];

        if(xparent == yparent)return;

        if(rank[xparent] > rank[yparent]){
            parent[yparent] = xparent;
        }else if(rank[xparent] < rank[yparent]){
            parent[xparent] = yparent;
        }else{
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i<n; i++)parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);

                edges.push_back({i, j, w});
            }
        }

        sort(edges.begin(), edges.end(),
             [&](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });

        int ans = 0;
        for(auto vec : edges){
            int u = vec[0], v = vec[1], w = vec[2];

            if(find(u) == find(v))continue;

            unionset(u,v);
            ans+= w;
        }
        return ans;
        
    }
};