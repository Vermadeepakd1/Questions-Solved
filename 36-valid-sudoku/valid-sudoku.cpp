class Solution {

    bool checkbox(vector<vector<char>>& board, int r, int c){
        vector<int> cnt(10,0);
        for(int i = r; i< r+3; i++){
            for(int j =c; j<c+3; j++){
                if(board[i][j] != '.'){
                    cnt[board[i][j] - '0']++;

                    if(cnt[board[i][j] - '0'] > 1) return false;

                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //row check
        for(int i = 0; i<9; i++){
            vector<int> cnt(10,0);
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    cnt[board[i][j] - '0']++;

                    if(cnt[board[i][j] - '0'] > 1) return false;

                }
            }
        }
        //col check
        for(int i = 0; i<9; i++){
            vector<int> cnt(10,0);
            for(int j = 0; j<9; j++){
                if(board[j][i] != '.'){
                    cnt[board[j][i] - '0']++;

                    if(cnt[board[j][i] - '0'] > 1) return false;

                }
            }
        }
        //3 * 3 check
        for(int i = 0; i <9; i+=3){
            for(int j = 0; j<9; j+=3){
                if(!checkbox(board, i ,j))return false;
            }
        }

        return true;
    }
};