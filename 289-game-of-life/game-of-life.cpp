class Solution {
public:
    vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> old = board;
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                int livecnt = 0;
                for(int k = 0; k<8; k++){
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];

                    if(ni >=0 && nj >=0 && ni<m && nj<n)livecnt+=old[ni][nj];
                }
                if(board[i][j]==1){
                    if(livecnt <2)board[i][j]=0;
                    else if(livecnt >3)board[i][j]=0;
                }else {
                    if(livecnt == 3)board[i][j]=1;
                }
            }

        }
    }
};