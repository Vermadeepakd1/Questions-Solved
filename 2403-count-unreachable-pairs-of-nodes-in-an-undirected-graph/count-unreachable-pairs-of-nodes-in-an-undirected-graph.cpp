class Solution {
    vector<int>  rank,parent;

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionset(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
        else{
            rank[y_parent]++;
            parent[x_parent] = y_parent;
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n);
        parent.resize(n);

        for(int i = 0; i< n; i++){
            rank[i] = 0;
            parent[i] = i;
        }

        for(auto &v : edges){
            unionset(v[0],v[1]);
        }

        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            mp[find(i)]++;
        }

        long long result = 0;
        long long rem = n;

        for(auto it : mp){
            long long size = it.second;
            rem -= size;
            result += size * rem;
        }
        return result;
    }
};