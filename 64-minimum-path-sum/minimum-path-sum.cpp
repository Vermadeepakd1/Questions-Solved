class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n;j++){
                int mini = INT_MAX;
                if(i != 0)mini = min(mini, dp[i-1][j]);
                if(j!=0)mini = min(mini, dp[i][j-1]);
                if(mini ==  INT_MAX)mini = 0;
                dp[i][j]= grid[i][j]+mini;
            }
        }
        return dp[m-1][n-1];
    }
};