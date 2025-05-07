class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> rowset, colset;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowset.insert(i);
                    colset.insert(j);
                }
            }
        }
        for (int x : rowset) {
            for (int i = 0; i < m; i++) {
                matrix[x][i] = 0;
            }
        }
        for (int y : colset) {
            for (int i = 0; i < n; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};