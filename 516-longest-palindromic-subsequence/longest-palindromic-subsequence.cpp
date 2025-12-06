class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int maxi = 1;
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int l = 0; l < n; l++){
            for(int i = 0; i<n-l; i++){
                int j = i+l;

                if(i==j)dp[i][j]=1;
                else if(l==1){
                    if(s[i] == s[j]) dp[i][j] = 2;
                }else{
                    if(s[i] == s[j] )
                    dp[i][j] = 2 +dp[i+1][j-1];
                    else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};