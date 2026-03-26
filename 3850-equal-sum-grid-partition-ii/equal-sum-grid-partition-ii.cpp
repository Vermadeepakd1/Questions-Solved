class Solution {
    vector<vector<int>> rotate90(const vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[j][rows - 1 - i] = matrix[i][j];
            }
        }
        return rotated;
    }

    bool canpartition(const vector<vector<int>>& grid, long long totalSum) {
        set<long long> st; 
        int m = grid.size(), n = grid[0].size();
        long long pre = 0;

        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                pre += grid[i][j];
                st.insert((long long)grid[i][j]); 
            }
            long long post = totalSum - pre;
            long long diff = pre - post;

            if(diff == 0) return true;
            
            if(i == 0){
                if((long long)grid[0][0] == diff || (long long)grid[0][n - 1] == diff) return true;
            } else if(n == 1){
                if((long long)grid[0][0] == diff || (long long)grid[i][0] == diff) return true;
            } else {
                if(st.count(diff)) return true;
            }
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();
        long long totalSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }
        
        if (canpartition(grid, totalSum)) return true;
        
        for (int i = 0; i < 3; i++) {
            grid = rotate90(grid);
            if (canpartition(grid, totalSum)) return true;
        }

        return false;
    }
};