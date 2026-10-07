class Solution {
public:
    int dp[101][101][201];
    bool check(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (k == s3.length())
            return true;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool ans = false;
        if (i < s1.length() && s1[i] == s3[k]) {
            ans |= check(s1, s2, s3, i + 1, j, k + 1);
        }
        if (j < s2.length() && s2[j] == s3[k]) {
            ans |= check(s1, s2, s3, i, j + 1, k + 1);
        }
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        if (s3.length() != s1.length() + s2.length())
            return false;
        return check(s1, s2, s3, 0, 0, 0);
    }
};