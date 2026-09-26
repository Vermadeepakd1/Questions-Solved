class Solution {
public:
    bool ispossible(vector<vector<bool>>&board,  int row, int col){
        for(int i = 0; i<row; i++){
            if(board[i][col])return false;
        }
        int x = row, y=col;
        while(x>=0 && y>=0){
            if(board[x][y])return false;
            x--;
            y--;
        }
        x = row, y=col;
        while(x>=0 && y<board.size()){
            if(board[x][y])return false;
            x--;
            y++;
        }
        return true;
    }
    int cnt = 0;
    void placequeen(int n,  vector<vector<bool>>&board, int idx){
        if(idx == n){
            cnt++;
            return;
        }
        for(int i = 0; i<n; i++){
            if(ispossible(board,idx,i)){
                board[idx][i]=true;
                placequeen(n,board,idx+1);
            }
            board[idx][i]=false;
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>>board(n,vector<bool>(n,false));
        for(int i =0; i<n; i++){
            board[0][i] = true;
            placequeen(n,board,1);
            board[0][i]=false;
        }
        return cnt;
    }
};