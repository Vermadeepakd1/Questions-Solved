class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> prev(n, {0, 0}), curr(n, {0, 0});
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = prev[j].first + ((j > 0) ? curr[j - 1].first : 0) -
                        ((j > 0) ? prev[j - 1].first : 0);
                int y = prev[j].second + ((j > 0) ? curr[j - 1].second : 0) -
                        ((j > 0) ? prev[j - 1].second : 0);
                if (grid[i][j] == 'X')
                    x++;
                else if (grid[i][j] == 'Y')
                    y++;

                curr[j].first = x;
                curr[j].second = y;
                if (curr[j].first == curr[j].second && curr[j].first > 0)
                    cnt++;
            }
            prev = curr;
        }
        return cnt;
    }
};