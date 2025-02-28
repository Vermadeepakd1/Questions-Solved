class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0, curr = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 2 < m && j + 2 < n) {
                    curr = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                            grid[i + 1][j + 1] + grid[i + 2][j] +
                            grid[i + 2][j + 1] + grid[i + 2][j + 2];
                    maxi = max(curr, maxi);
                }
            }
        }
        return maxi;
    }
};