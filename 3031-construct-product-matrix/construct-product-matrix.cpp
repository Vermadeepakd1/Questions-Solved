class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int M = 12345;

        vector<vector<long long>> prefix(n,vector<long long>(m,1)),suffix(n,vector<long long>(m,1));
        vector<vector<int>> result(n,vector<int>(m,1));
        long long prod = 1;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(i==0 && j == 0)prefix[i][j] = 1;
                else if(j==0)prefix[i][j] = (prefix[i-1][m-1]%M * grid[i-1][m-1]%M)%M;
                else prefix[i][j] = (prefix[i][j-1]%M * grid[i][j-1]%M)%M;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j =m-1; j>=0; j--){
                if(i==n-1 && j == m-1)suffix[i][j] = 1;
                else if(j==m-1)suffix[i][j] = (suffix[i+1][0]%M * grid[i+1][0]%M)%M;
                else suffix[i][j] = (suffix[i][j+1]%M * grid[i][j+1]%M)%M;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j =m-1; j>=0; j--){
                result[i][j] = ((prefix[i][j]%M) * (suffix[i][j]%M))%M;
            }
        }
        return result;

    }
};