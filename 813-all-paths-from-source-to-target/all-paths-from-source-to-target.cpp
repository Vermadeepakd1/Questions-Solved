class Solution {
    void dfs(int node, int dest, unordered_map<int, bool>& visited,
             vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int> temp) {

        if (!visited[node]) {

            temp.push_back(node);
            visited[node] = true;
        }
        if (node == dest) {
            ans.push_back(temp);
            temp.clear();
        }
        for(int n: graph[node]){
            dfs(n,dest,visited,graph,ans,temp);
        }
        visited[node] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, bool> visited;
        vector<vector<int>> ans;
        vector<int> temp;

        int n = graph.size();
        int src = 0, dest = n - 1;

        dfs(src, dest, visited, graph, ans, temp);
        return ans;
    }
};