class Solution {
    int m, n;
    int dp[100][100][202];

public:
    bool findsol(vector<vector<char>>& grid, int i, int j, int score) {
        if (i == m - 1 && j == n - 1) {
            return score == 1;
        }

        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        score += ((grid[i][j] == '(') ? 1 : -1);
        if (score < 0)
            return false;
        if (dp[i][j][score] != -1)
            return dp[i][j][score];

        return dp[i][j][score] = findsol(grid, i + 1, j, score) ||
                                 findsol(grid, i, j + 1, score);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        return findsol(grid, 0, 0, 0);
    }
};