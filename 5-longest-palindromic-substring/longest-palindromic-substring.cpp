class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start = 0, maxlen = 1;

        for(int l = 0; l<n; l++){
            for(int i = 0; i<n-l; i++){
                int j = i+l;
                if(i == j)dp[i][j] = true;
                else if(s[i] == s[j] && l==1){
                    dp[i][j] = true;
                }else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                if (dp[i][j] && l + 1 > maxlen) {
                    maxlen = l + 1;
                    start = i;
                }
            }
        }

        return s.substr(start,maxlen);
    }
};