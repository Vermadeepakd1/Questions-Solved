class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (i - j >= 0 && dp[i - j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        if (dp[amount] != INT_MAX)
            return dp[amount];
        return -1;
    }
};