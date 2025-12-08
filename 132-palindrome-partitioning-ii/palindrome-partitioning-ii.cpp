class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int l = 0; l<n; l++){
            for(int i = 0; i<n-l; i++){
                int j = i+l;
                if(l == 0)dp[i][j] = true;
                else if(s[i] == s[j]){
                    if(l == 1)dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }

        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            if(dp[0][i])ans[i] = 0;
            else{
                ans[i] = INT_MAX;
                for(int k = 0; k<i; k++){
                    if(dp[k+1][i] && 1 + ans[k] < ans[i]){
                        ans[i] = 1 + ans[k];
                    }
                }
            }
        }

        return ans[n-1];
    }
};