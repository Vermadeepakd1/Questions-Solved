class Solution {
public:
    int d;

    void dfs(unordered_map<int,vector<int>>& adj,
        unordered_map<int,bool>& visited,int node, int curr){
            visited[node] = true;
            d = max(d,curr);

            for(auto i : adj[node]){
                if(!visited[i]){
                    dfs(adj,visited,i,curr+1);
                }
            }
        }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> visited;

        for(auto &v : edges){
            int a = v[0],b=v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        d = 0;
        dfs(adj,visited,1,0);
        cout << d << endl;
        if(d==0)return 0 ;
        long long ans = 1;
        long long base = 2;
        int power = d - 1;
        int mod = 1e9 + 7;

        while(power > 0) {
            if(power % 2 == 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            power /= 2;
        }

        return ans;
    }
};