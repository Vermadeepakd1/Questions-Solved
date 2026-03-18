class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(),  n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> pref(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = grid[i][j];

                if (i > 0) curr += pref[i - 1][j];
                if (j > 0) curr += pref[i][j - 1];
                if (i > 0 && j > 0) curr -= pref[i - 1][j - 1];

                pref[i][j] = curr;

                if (pref[i][j] <= k) {
                    cnt++;
                } else {
                    break; 
                }
            }
        }

        return cnt;
    }
};