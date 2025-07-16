// User function Template for C++

class Solution {
    int solve(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n]!= -1) return dp[n];
        
        int ans = n;
        for(int i = 1; i*i <= n; i++){
            int temp  = i*i;
            ans = min(ans, 1 + solve(n - temp, dp));
        }
        return dp[n] = ans;
    }
  public:
    int MinSquares(int n) {
        // Code here
        vector<int> dp(n+1,-1);
        int ans = solve(n,dp);
        return ans;
    }
};