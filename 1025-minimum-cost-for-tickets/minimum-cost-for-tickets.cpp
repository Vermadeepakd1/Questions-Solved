class Solution {
    int n;
    int memo[366];

    int solve(vector<int>& days, vector<int>& costs, int idx) {
        if (idx >= n)
            return 0;

        if (memo[idx] != -1)
            return memo[idx];

        int option1 = costs[0] + solve(days, costs, idx + 1);

        int next_idx7 =
            upper_bound(days.begin(), days.end(), days[idx] + 6) - days.begin();
        int option7 = costs[1] + solve(days, costs, next_idx7);

        int next_idx30 = upper_bound(days.begin(), days.end(), days[idx] + 29) -
                         days.begin();
        int option30 = costs[2] + solve(days, costs, next_idx30);

        return memo[idx] = min({option1, option7, option30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(memo, -1, sizeof(memo));
        return solve(days, costs, 0);
    }
};