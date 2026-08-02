class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec : flights){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v,w});
        }
        
        vector<int> costTracker(n, INT_MAX);
        costTracker[src] = 0;
        
        int mincost = INT_MAX;
        queue<pair<int,int>> q;
        
        q.push({src,0});
        int steps = 0;

        while(!q.empty() && steps <= k){
            int l = q.size();

            for(int i = 0; i < l ; i++){
                auto [u, dist] = q.front();
                q.pop();

                for(auto [v, w] : adj[u]){
                    if(w + dist < costTracker[v]){
                        costTracker[v] = w + dist;
                        
                        if (v == dst) {
                            mincost = min(mincost, w + dist);
                        } else {
                            q.push({v, w + dist});
                        }
                    }
                }
            }
            steps++;
        }
        return (mincost == INT_MAX) ? -1 : mincost;
    }
};