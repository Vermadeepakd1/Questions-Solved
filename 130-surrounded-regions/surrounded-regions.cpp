class Solution {
    int dir[5] = {-1, 0, 1, 0, -1};
    
    bool check(vector<vector<char>>& board, int x ,int y, vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        q.push({x,y});
        visited[x][y] = true;
        int m = board.size(), n = board[0].size();
        
        bool isSurrounded = true; 

        while(!q.empty()){
            auto [ox,oy] = q.front();
            q.pop();
            
            if(ox == 0 || oy == 0 || ox == m-1 || oy == n-1) {
                isSurrounded = false; 
            }
            
            for(int i = 0; i < 4; i++){
                int nx = ox + dir[i];
                int ny = oy + dir[i+1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && board[nx][ny] == 'O'){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return isSurrounded;
    }
    
    void capture(vector<vector<char>>& board, int i , int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        int m = board.size(), n = board[0].size();
        board[i][j] = 'X';

        while(!q.empty()){
            auto [ox,oy] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = ox + dir[i];
                int ny = oy + dir[i+1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O'){
                    q.push({nx,ny});
                    board[nx][ny] = 'X';
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !visited[i][j] && check(board, i, j, visited)){
                    capture(board, i, j);
                }
            }
        }
    }
};