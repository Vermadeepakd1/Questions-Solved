class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> store;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                store.push_back(grid[i][j]);
            }
        }
        int total = m * n;
        if (total == 1)
            return grid;
            k %= total;
        if (k == 0) return grid;
        rotate(store.begin(), store.end()  - k, store.end());
        int x = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = store[x++];
            }
        }
        return grid;
    }
};