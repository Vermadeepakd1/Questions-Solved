class Solution {
    int calculate(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& dp) {
        if (k == 0 || idx >= events.size()) {
            return 0;
        }

        if (dp[idx][k] != -1) return dp[idx][k];

        // Option 1: Skip current event
        int skip = calculate(events, idx + 1, k, dp);

        // Option 2: Attend current event
        auto it = upper_bound(events.begin(), events.end(), events[idx][1],
                              [](int value, const vector<int>& event) {
                                  return value < event[0];
                              });
        int nextIdx = it - events.begin();
        int take = events[idx][2] + calculate(events, nextIdx, k - 1, dp);

        return dp[idx][k] = max(skip, take);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return calculate(events, 0, k, dp);
    }
};
