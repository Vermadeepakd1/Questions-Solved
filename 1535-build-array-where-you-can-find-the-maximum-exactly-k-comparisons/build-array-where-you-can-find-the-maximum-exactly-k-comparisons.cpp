class Solution {
    int dp[101][51][101];
    int mod = 1e9+7;

    int solve(int idx, int cost, int maxi, int n, int m, int k) {
        if (idx == n) {
            if (cost == k)
                return 1;
            return 0;
        }
        if (dp[idx][cost][maxi] != -1)
            return dp[idx][cost][maxi];
        int result = 0;
        for (int i = 1; i <= m; i++) {
            if (i > maxi) {
                result = (result +  solve(idx + 1, cost + 1, i, n, m, k))%mod;
            } else {
                result = (result + solve(idx + 1, cost, maxi, n, m, k))%mod;
            }
        }

        return dp[idx][cost][maxi] = result;
    }

public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, m, k);
    }
};