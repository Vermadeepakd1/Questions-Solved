class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rpresum(m), rsufsum(m), cpresum(n), csufsum(n);

        long long a = 0, b = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a += grid[i][j];
                b += grid[m - i - 1][j];
            }
            rpresum[i] = a;
            rsufsum[m - i - 1] = b;
        }
        a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                a += grid[i][j];
                b += grid[i][n-1-j];
            }
            cpresum[j] = a;
            csufsum[n-1-j] = b;
        }

        for(int i = 0; i<m-1; i++){
            if(rpresum[i]==rsufsum[i+1])return true;
        }
        for(int i = 0; i<n-1; i++){
            if(cpresum[i] == csufsum[i+1])return true;
        }
        return false;
    }
};