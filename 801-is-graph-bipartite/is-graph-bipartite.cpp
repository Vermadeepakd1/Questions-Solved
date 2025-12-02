class Solution {
    bool bfs(vector<vector<int>>& graph,vector<int> &color, int idx, int currcolor) {
        queue<pair<int,int>> q;
        q.push({idx,0});
        color[idx] = 0;
        while(!q.empty()){
            auto t = q.front();
            int node = t.first;
            int col = t.second;
            q.pop();

            for(int i : graph[node]){
                if(color[i] == col)return false;
                if(color[i] == -1){
                    q.push({i,1-col});
                    color[i] = 1-col;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !bfs(graph,color, i, 0)) {
                return false;
            }
        }
        return true;
    }
};