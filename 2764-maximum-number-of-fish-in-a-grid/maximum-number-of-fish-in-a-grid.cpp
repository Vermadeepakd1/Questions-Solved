class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        int maxi = 0;
        vector<pair<int,int>> directions = {{0,1},{-1,0},{0,-1},{1,0}};
        function<int(int,int)> dfs = [&](int r,int c){
            visited[r][c] = 1;
            int fishcount = grid[r][c];
            for (auto& dir : directions) {
                int nr = r + dir.first, nc = c + dir.second;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !visited[nr][nc]) {
                    fishcount += dfs(nr, nc);  // Add fish count from this neighbor
                }
            }

            return fishcount;
        };
        for(int i =0; i<m; i++){
            
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && visited[i][j] == 0){
                    maxi = max(maxi,dfs(i,j)) ;;
                } 
            }
        }
        return maxi;
    }
};