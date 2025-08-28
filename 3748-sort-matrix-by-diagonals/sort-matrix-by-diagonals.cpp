class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int j = n-1; j>0; j--){
            int row = 0, col = j;
            vector<int> temp;
            while(row < n && col < n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row = 0, col = j;
            int x = 0;
            while(row < n && col < n){
                grid[row][col] = temp[x];
                x++;
                row++;
                col++;
            }
        }
        for(int j = 0; j<n; j++){
            int row = j;
            int col = 0;
            vector<int> temp;
            while(row < n && col < n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.rbegin(),temp.rend());
            row = j, col = 0;
            int x = 0;
            while(row < n && col < n){
                grid[row][col] = temp[x];
                x++;
                row++;
                col++;
            }
        }

        return grid;
    }
};