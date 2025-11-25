class Solution {
    vector<int> h = {-1,0,1,0};
    vector<int> v = {0,-1,0,1};
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i <0 || i >= board.size() || j <0 || j >= board[0].size() || board[i][j] != 'O' )return;

        board[i][j] = 'S';

        for(int l = 0; l < 4; l++){
            int ni = i+h[l];
            int nj = j+ v[l];

            dfs(board,ni,nj);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i <n;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }
            if(board[i][m-1] == 'O')dfs(board,i,m-1);
        }

        for(int i = 0; i<m; i++){
            if(board[0][i] == 'O')dfs(board,0,i);
            if(board[n-1][i] == 'O')dfs(board,n-1,i);
        }


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }
    }
};