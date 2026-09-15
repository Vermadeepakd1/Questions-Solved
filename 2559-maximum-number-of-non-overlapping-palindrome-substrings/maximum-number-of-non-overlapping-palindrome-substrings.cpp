class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> ispalin(n, vector<bool>(n, false));
        for (int g = 0; g < n; g++) {
            for (int i = 0; i < n - g; i++) {
                int j = g + i;
                if (i == j) {
                    ispalin[i][j] = true;
                } else if (s[i] == s[j]) {
                    if (j == i + 1) {
                        ispalin[i][j] = true;
                    } else {
                        ispalin[i][j] = ispalin[i + 1][j - 1];
                    }
                }
            }
        }


        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            if (i >= k && ispalin[i - k][i - 1]) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            if (i >= k + 1 && ispalin[i - k - 1][i - 1]) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};