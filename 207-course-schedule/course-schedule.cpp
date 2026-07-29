class Solution {
    bool check(unordered_map<int,vector<int>>&adj,vector<bool>&visited, vector<bool>&inrecursion, int node){
        visited[node]=true;
        inrecursion[node]=true;

        for(auto nbr: adj[node]){
            if(!visited[nbr] && !check(adj,visited,inrecursion,nbr)){
                 return false;
            }else if(visited[nbr] && inrecursion[nbr]){
                return false;
            }
        }
        inrecursion[node] =false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto &e : prerequisites){
            int u = e[0],  v = e[1];
            adj[u].push_back(v);
        }

        vector<bool>visited(numCourses,false);

        
        for(int i = 0; i<numCourses; i++){
            vector<bool> inrecursion(numCourses,false);
            if(!visited[i] && !check(adj,visited,inrecursion,i)){
                 return false;
            }
        }
        return true;

    }
};