class Solution {
public:
    typedef long long ll;
    typedef pair<long long,int> pr;

    bool check(int mid, int n, ll k,unordered_map<int,vector<vector<int>>>&adj ){
        vector<ll>result(n,LLONG_MAX);

        priority_queue<pr,vector<pr>, greater<pr>> pq;

        result[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d>k)return false;

            if(node == n-1)return true;

            if(result[node] < d)continue;

            for(auto &vec : adj[node]){
                int nbr = vec[0];
                int cst = vec[1];

                if(cst < mid)continue;
                if(d + cst < result[nbr]){
                    result[nbr] = d + cst;
                    pq.push({result[nbr], nbr});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        int l = INT_MAX, r = 0;

        unordered_map<int,vector<vector<int>>>adj;

        for(auto &e : edges){
            int u = e[0], v =e[1], cst= e[2];

            if(!online[u] || !online[v] || cst > k)continue;

            adj[u].push_back({v,cst});
            l = min(l,cst);
            r = max(r,cst);
        }

        int ans = -1;

        while(l<=r){
            int mid = l +(r-l)/2;

            if(check(mid,n,k,adj)){
                ans = mid;
                l = mid+1;
            }else r= mid-1;
        }
        return ans;
    }
};