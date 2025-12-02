class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int idx,
             int currcolor) {
        color[idx] = currcolor;
        for (int nbr : graph[idx]) {
            if (color[nbr] == color[idx])
                return false;
            else if (color[nbr] == -1) {
                int nextcolor = (currcolor == 0) ? 1 : 0;
                if (!dfs(graph, color, nbr, nextcolor))
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(graph, color, i, 0)) {
                return false;
            }
        }
        return true;
    }
};