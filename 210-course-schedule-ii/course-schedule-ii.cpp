class Solution {
    bool cycle = false;

    void dfs(unordered_map<int,vector<int>> &adj, int idx,vector<bool> &visited, vector<bool> &inrecursion, stack<int>&st){
        visited[idx] = true;
        inrecursion[idx] = true;

        for(int nbr : adj[idx]){
            if(inrecursion[nbr]){
                cycle =true;
                return;
            }
            if(!visited[nbr])
            dfs(adj,nbr, visited,inrecursion,st);
        }

        inrecursion[idx] = false;
        st.push(idx);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        int n = numCourses;

        vector<bool> inrecursion(n,false), visited(n,false);

        for(auto &i : prerequisites){
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);

        }

        stack<int> st;

        for(int i = 0; i<n; i++){
            if(!visited[i] ){
                dfs(adj,i,visited,inrecursion,st);
            }
        }

        if(cycle)return {};

        vector<int> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};