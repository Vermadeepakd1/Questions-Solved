class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count(n * n + 1, 0);
        int a, b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
                if (count[grid[i][j]] > 1) {
                    a = grid[i][j];
                }
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 0) {
                b = i;
                break;
            }
        }
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};