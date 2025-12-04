class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (i == 0) {
                    dp[j][j + i] = true;
                    cnt++;
                } else if (i == 1) {
                    if (s[j] == s[j + i]) {
                        dp[j][j + i] = true;
                        cnt++;
                    }
                } else {
                    if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
                        dp[j][j + i] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};