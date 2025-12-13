class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += fruits[i][i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i < j && i + j < n - 1) {
                    dp[i][j] = 0;
                } else if (i > j && i + j < n - 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = fruits[i][j];
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] += max({dp[i - 1][j - 1], dp[i - 1][j],
                                 (j + 1 < n) ? dp[i - 1][j + 1] : 0});
            }
        }

        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                dp[i][j] += max({dp[i][j - 1], dp[i - 1][j - 1],
                                 (i + 1 < n) ? dp[i + 1][j - 1] : 0});
            }
        }

        return result + dp[n - 2][n - 1] + dp[n - 1][n - 2];
    }
};