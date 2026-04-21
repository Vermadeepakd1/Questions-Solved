class Solution {
    void dfs(vector<int>& source, vector<int>& target,int idx, vector<bool>&visited, set<int>&st,unordered_map<int,int>&mp1, unordered_map<int,int>&mp2,vector<vector<int>> &graph){
        visited[idx] = true;
        st.insert(source[idx]);
        st.insert(target[idx]);
        mp1[source[idx]]++;
        mp2[target[idx]]++;
        // found[source[idx]][0]++;
        // found[target[idx]][1]++;

        for(auto nbr : graph[idx]){
            if(!visited[nbr]){
                dfs(source,target,nbr, visited,st,mp1,mp2,graph);
            }
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n =source.size();
        vector<vector<int>> graph(n);

        for(auto &vec : allowedSwaps){
            int u = vec[0], v= vec[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n+1,false);
        int ans = 0;
        for(int i =0; i<n; i++){
            if(!visited[i]){
                set<int> st;
                unordered_map<int,int> mp1,mp2;
                dfs(source,target,i,visited,st,mp1,mp2,graph);
                // for(int i = 0 ; i<=n; i++){
                //     ans += abs(found[i][0] - found[i][1]);
                // }

                for(int i : st){
                    ans += abs(mp1[i]-mp2[i]);
                }
            }
        }
        return ans/2;

    }
};