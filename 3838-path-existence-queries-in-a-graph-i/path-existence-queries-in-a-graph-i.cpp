class Solution {
public:
    vector<int> rank,parent;

    int find(int i ){
        if(parent[parent[i]] != parent[i]){
            return parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unionset(int x, int y ){
        int xparent = find(x);
        int yparent = find(y);

        if(xparent == yparent)return;

        if (rank[xparent] < rank[yparent]) {
            parent[xparent] = yparent;
        } else if (rank[yparent] < rank[xparent]) {
            parent[yparent] = xparent;
        } else {
            parent[yparent] = xparent;
            rank[xparent]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0; i<n; i++)parent[i] = i;

        for(int i =1 ; i<n; i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                unionset(i-1, i);
            }
        }
        vector<bool>result;

        for(auto &q : queries){
            int u = q[0] , v = q[1];

            if(find(u) == find(v)){
                result.push_back(true);
            }else result.push_back(false);
        }
        return result;
    }
};