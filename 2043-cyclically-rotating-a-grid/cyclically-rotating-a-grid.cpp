class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < min(m, n) / 2; i++) {
            vector<int> temp;
            int sr = i, er = m - i - 1, sc = i, ec = n - i - 1;

            for(int j = sr; j <= er; j++) temp.push_back(grid[j][sc]); 
            for(int j = sc + 1; j <= ec; j++) temp.push_back(grid[er][j]);
            for(int j = er - 1; j >= sr; j--) temp.push_back(grid[j][ec]);
            
            for(int j = ec - 1; j > sc; j--) temp.push_back(grid[sr][j]); 

            int rotations = k % temp.size();
            rotate(temp.rbegin(), temp.rbegin() + rotations, temp.rend());

            int idx = 0;
            for(int j = sr; j <= er; j++) grid[j][sc] = temp[idx++];
            for(int j = sc + 1; j <= ec; j++) grid[er][j] = temp[idx++];
            for(int j = er - 1; j >= sr; j--) grid[j][ec] = temp[idx++];
            
            for(int j = ec - 1; j > sc; j--) grid[sr][j] = temp[idx++];
        }
        
        return grid;
    }
};