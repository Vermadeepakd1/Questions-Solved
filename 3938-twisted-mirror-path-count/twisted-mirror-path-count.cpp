class Solution {
    int m, n;

    bool isvalid(int i, int j) { return (i >= 0 && j >= 0 && i < m && j < n); }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        long long MOD = 1e9 + 7;

        // dp[i][j][0] =  RIGHT (from the left cell)
        // dp[i][j][1] =  DOWN (from the top cell)
        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, 0)));

        if (n > 1)
            dp[0][1][0] = 1;
        if (m > 1)
            dp[1][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 1) || (i == 1 && j == 0) ||
                    (i == 0 && j == 0)) {
                    continue;
                }
                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                    } else {
                        dp[i][j][0] = dp[i][j - 1][1];
                    }
                }

                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                    } else {
                        dp[i][j][1] = dp[i - 1][j][0];
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};
