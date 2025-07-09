class Solution {
    long long solve(vector<vector<int>>& questions, int idx, vector<int> &dp) {
        if (idx >= questions.size()) {
            return 1LL * 0;
        }

        if(dp[idx] != -1) return dp[idx];

        long long solved =
            questions[idx][0] + solve(questions, idx + questions[idx][1] + 1,dp);
        long long skip = 1LL * solve(questions, idx + 1,dp);

        dp[idx] = max(skip,solved);
        return max(skip, solved);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<int> dp(n+1, -1);
        long long ans = solve(questions, 0,dp);
        return ans;
    }
};