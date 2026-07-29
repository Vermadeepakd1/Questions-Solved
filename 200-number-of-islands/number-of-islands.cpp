class Solution {
    int dir[4][2] = {{-1,0},{1,0},{0,-1}, {0,1}};
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k = 0; k<4; k++){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if(nx >=0 && nx < grid.size()  && ny >=0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(grid,visited,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};