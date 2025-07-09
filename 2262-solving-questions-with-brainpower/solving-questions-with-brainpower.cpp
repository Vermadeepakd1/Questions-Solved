class Solution {
    long long solve(vector<vector<int>>& questions, int idx, vector<long long>& dp) {
        int n = questions.size();
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            long long nextIndex = 1LL * i + questions[i][1] + 1;
            long long solved =
                questions[i][0] + ((nextIndex < n) ? dp[nextIndex] : 0);

            long long skip = 1LL * dp[i + 1];

            dp[i] = max(skip, solved);
        }

        return dp[0];
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        long long ans = solve(questions, 0, dp);
        return ans;
    }
};