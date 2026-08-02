class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 0; l < n; l++) {
            for (int i = 0; i < n - l; i++) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = piles[i];
                else
                    dp[i][j] =
                        max(piles[j] - dp[i][j - 1], piles[i] - dp[i + 1][j]);
            }
        }
        return (dp[0][n - 1] > 0);
    }
};