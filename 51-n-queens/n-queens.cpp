class Solution {

    void solve(vector<string>& board, vector<vector<string>>& ans,
               vector<bool>& cols, vector<bool>& dg1, vector<bool>& dg2,
               int crow, int n) {
        if (crow == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!cols[i] && !dg1[crow + i] && !dg2[crow - i + n - 1]) {
                board[crow][i] = 'Q';

                cols[i] = true;
                dg1[crow + i] = true;
                dg2[crow - i + n - 1] = true;

                solve(board, ans, cols, dg1, dg2, crow + 1, n);

                cols[i] = false;
                dg1[crow + i] = false;
                dg2[crow - i + n - 1] = false;

                board[crow][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false), dg1(2 * n, false), dg2(2 * n, false);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(board, ans, cols, dg1, dg2, 0, n);

        return ans;
    }
};