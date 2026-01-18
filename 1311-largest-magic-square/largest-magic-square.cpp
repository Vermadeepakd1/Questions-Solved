class Solution {
    bool ismagicsquare(vector<vector<int>>& grid, int x, int y, int n){
        bool calc = false;
        int sum = 0;
        //rowsum
        for(int i =x; i<x+n; i++){
            int temp = 0;
            for(int j = y; j<y+n; j++){
                temp += grid[i][j];
            }
            if(!calc){
                calc =true;
                sum = temp;
            }else{
                if(sum != temp)return false;
            }
        }

        //colsum
        for(int i =y; i<y+n; i++){
            int temp = 0;
            for(int j = x; j<x+n; j++){
                temp += grid[j][i];
            }
            if(sum != temp)return false;
        }

        //diagsum
        int i = x, j = y;
        int temp=0;
        while(i < x+n && j < y+n){
            temp += grid[i][j];
            i++;
            j++;
        }
        if(sum != temp)return false;
        i=x+n-1;
        j=y;
        temp = 0;
        while(i>=x && j < y+n){
            temp += grid[i][j];
            i--;
            j++;
        }
        if(sum != temp)return false;

        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 1;
        for(int l = 2; l<=min(n,m); l++){
            bool found = false;
            for(int i = 0; i<=n-l; i++){
                for(int j = 0; j<=m-l; j++){
                    if(ismagicsquare(grid,i,j,l)){
                        maxi = max(maxi,l);
                        found = true;
                        break;
                    }
                }
                if(found)break;
            }
        }
        return maxi;
    }
};