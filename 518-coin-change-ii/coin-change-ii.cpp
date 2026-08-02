class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int j : coins) {
            for (int i = j; i <= amount; i++) {
                dp[i] += dp[i - j];
            }
        }
        return dp[amount];
    }
};