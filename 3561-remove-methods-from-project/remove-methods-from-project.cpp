class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool>visited(n,false);
        bool flag = false;

        unordered_map<int,vector<int>> adj;

        for(auto &vec : invocations){
            int u = vec[0], v =vec[1];
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        visited[k] = true;

        while(!q.empty()){
            int t = q.front();
            q.pop();

            for(auto nbr : adj[t]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        for(auto &vec : invocations){
            int u = vec[0], v = vec[1];
            if(!visited[u] && visited[v]){
                flag = true;
                break;
            }
        }

        vector<int> result;
        for(int i = 0; i<n; i++){
            if(!flag && visited[i])continue;
            else result.push_back(i);
        }

        return result;
    }
};