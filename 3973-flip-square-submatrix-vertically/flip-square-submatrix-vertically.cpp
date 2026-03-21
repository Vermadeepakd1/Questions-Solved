class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startx =x, endx = x+k-1;
        while(startx < endx){
            for(int i = y; i<y+k; i++){
                swap(grid[startx][i],grid[endx][i]);
            }
            startx++;
            endx--;
        }
        return grid;
    }
};