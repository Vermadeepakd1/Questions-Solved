class Solution {
    bool solve(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int idx, int row, int col, int l, int m) {
        if (idx == word.length()) return true;

        // up
        if (row - 1 >= 0 && !visited[row - 1][col] && board[row - 1][col] == word[idx]) {
            visited[row - 1][col] = true;
            if (solve(board, word, visited, idx + 1, row - 1, col, l, m)) return true;
            visited[row - 1][col] = false;
        }

        // down
        if (row + 1 < l && !visited[row + 1][col] && board[row + 1][col] == word[idx]) {
            visited[row + 1][col] = true;
            if (solve(board, word, visited, idx + 1, row + 1, col, l, m)) return true;
            visited[row + 1][col] = false;
        }

        // right
        if (col + 1 < m && !visited[row][col + 1] && board[row][col + 1] == word[idx]) {
            visited[row][col + 1] = true;
            if (solve(board, word, visited, idx + 1, row, col + 1, l, m)) return true;
            visited[row][col + 1] = false;
        }

        // left
        if (col - 1 >= 0 && !visited[row][col - 1] && board[row][col - 1] == word[idx]) {
            visited[row][col - 1] = true;
            if (solve(board, word, visited, idx + 1, row, col - 1, l, m)) return true;
            visited[row][col - 1] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int l = board.size(), m = board[0].size();
        vector<vector<bool>> visited(l, vector<bool>(m, false));

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (solve(board, word, visited, 1, i, j, l, m)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
