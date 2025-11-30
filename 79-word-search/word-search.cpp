class Solution {
    vector<int> hd = {-1, 0, 1, 0};
    vector<int> vd = {0, -1, 0, 1};
    bool solve(vector<vector<char>>& board, string& word, int idx, int row,
               int col, int l, int m) {
        if (idx == word.length())
            return true;

        for (int i = 0; i < 4; i++) {
            int nrow = row + hd[i];
            int ncol = col + vd[i];

            if (nrow >= 0 && ncol >= 0 && ncol < m && nrow < l &&
                board[nrow][ncol] == word[idx]) {
                board[nrow][ncol] = '#';
                if (solve(board, word, idx + 1, nrow, ncol, l, m))
                    return true;
                board[nrow][ncol] = word[idx];
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int l = board.size(), m = board[0].size();

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (solve(board, word, 1, i, j, l, m))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
