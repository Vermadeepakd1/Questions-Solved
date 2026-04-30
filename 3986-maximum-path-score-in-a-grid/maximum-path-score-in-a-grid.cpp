class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, int cost, int k, vector<vector<vector<int>>>& dp, int m, int n) {

        if (cost > k) return INT_MIN / 4;

        int add = grid[i][j];
        int newcost = cost+  (grid[i][j] != 0 ? 1 : 0);
        if (newcost > k) return INT_MIN / 4;

        if (i == m - 1 && j == n - 1) {
            return add;
        }

        if (dp[i][j][cost] != INT_MIN) return dp[i][j][cost];

        int best = INT_MIN / 4;

        if (i + 1 < m) {
            int down = dfs(grid, i + 1, j, newcost, k, dp, m, n);
            if (down != INT_MIN / 4) best = max(best, add + down);
        }
        if (j + 1 < n) {
            int right = dfs(grid, i, j + 1, newcost, k, dp, m, n);
            if (right != INT_MIN / 4) best = max(best, add + right);
        }

        dp[i][j][cost] = best;
        return best;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));

        int ans = dfs(grid, 0, 0, 0, k, dp, m, n);
        if (ans <= INT_MIN / 8) return -1; 
        return ans;
    }
};
