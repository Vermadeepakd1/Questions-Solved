class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int curr = health;
        priority_queue<vector<int>> pq;
        pq.push({curr-grid[0][0], 0, 0});

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        visited[0][0] = true;

        while (!pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();

            int h = v[0], cx = v[1], cy = v[2];
            if (h < 1)
                continue;
            if (cx == m - 1 && cy == n - 1 && h > 0)
                return true;

            for (auto& d : dir) {
                int x = cx + d[0], y = cy + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    pq.push({h - grid[x][y], x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }
};