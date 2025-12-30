class Solution {
    int m ,n;
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
        set<int> st;
        for(int r = 0; r<3; r++){
            for(int c = 0; c < 3; c++){
                if(grid[i+r][j+c] > 9 || grid[i+r][j+c] < 1)return false;
                if(st.find(grid[i+r][j+c]) != st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        int sum = grid[i][j] + grid[i][j+1]+grid[i][j+2];
        int rowsum = 0;
        int colsum = 0;
        for(int r = 0; r<3; r++){
            rowsum = 0, colsum = 0;
            for(int c = 0; c<3; c++){
                rowsum += grid[i+r][j+c];
                colsum += grid[i+c][j+r];
            }
            if(rowsum != sum || colsum != sum)return false;
        }
        if(grid[i][j] + grid[i+1][j+1]+ grid[i+2][j+2] != sum)return false;
        if(grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != sum)return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;

         m = grid.size();
         n = grid[0].size();

        if(m<3 || n < 3)return 0;
        
        for(int i=0; i<=m-3; i++){
            for(int j = 0; j<=n-3; j++){
                if(isMagicSquare(grid,i,j))cnt++;
            }
        }

        return cnt;
    }
};