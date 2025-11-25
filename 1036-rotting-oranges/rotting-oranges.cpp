class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (fresh && !q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; i++) {
                auto x = q.front();
                q.pop();
                int r = x.first, c = x.second;

                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                    fresh--;
                }

                if (r + 1 < n && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                    fresh--;
                }

                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                    fresh--;
                }

                if (c + 1 < m && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                    fresh--;
                }
            }
            time++;
        }
        if (fresh)
            return -1;
        return time;
    }
};