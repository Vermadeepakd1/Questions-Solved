class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int g = 0; g < n; g++){
            for(int i = 0; i < n - g; i++){
                int j = i + g;
                if(s[i] == s[j] && (g <= 2 || isPal[i + 1][j - 1])){
                    isPal[i][j] = true;
                }
            }
        }
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++){
            if(isPal[0][i]) {
                dp[i] = 0; 
            } else {
                dp[i] = i; 
                
                for(int j = 1; j <= i; j++){
                    if(isPal[j][i]){
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};