class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        // DP State: dp[i][j][rem] = count of paths to (i,j) with sum % k == rem
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0)continue;

                for(int l = 0; l < k; l++){
                    int newr = (l+grid[i][j])%k;
                    if(i>0)
                    dp[i][j][newr] = (dp[i][j][newr] + dp[i-1][j][l])%mod;

                    if(j > 0)
                    dp[i][j][newr] = (dp[i][j][newr] + dp[i][j-1][l])%mod;
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};