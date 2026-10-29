class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        int total = m * n;
        if (total == 1)
            return grid;
            k %= total;
        if (k == 0) return grid;

        vector<vector<int>> ans(m,vector<int>(n,0));


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int nidx = (i*n+j+k)%total;
                int ni = nidx/n;
                int nj = nidx%n;

                ans[ni][nj] = grid[i][j];
            }
        }
        return ans;
    }
};