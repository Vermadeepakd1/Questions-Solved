class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() , n = grid[0].size();

        vector<int> all;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                all.push_back(grid[i][j]);
            }
        }

        sort(all.begin(),all.end());
        int tomake = all[all.size()/2];

        int ans = 0;

        for(int i : all){
            if( abs(tomake-i) %x == 0 ){
                ans += abs(tomake-i)/x;
            }else{
                return -1;
            }
        }
        return ans;

    }
};