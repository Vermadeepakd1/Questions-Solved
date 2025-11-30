class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        int n = numCourses;

        vector<int> indegree(n,0);

        for(auto i :prerequisites ){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> result;
        int cnt = 0;
        queue<int> q;

        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                result.push_back(i);
                cnt++;

            }
        }

        while(!q.empty()){
            int t =q.front();
            q.pop();
            for(int i : adj[t]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                    result.push_back(i);
                    cnt++;
                }
            }
        }

        if(cnt == n)return result;
        return {};
    }
};