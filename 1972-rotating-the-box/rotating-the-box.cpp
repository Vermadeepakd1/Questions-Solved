class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(),n = boxGrid[0].size();
        for(auto &row : boxGrid){
            int last = n;
            for(int i = n-1; i>=0; i--){
                if(row[i] == '*'){
                    last = i;
                }else if(row[i] == '#'){
                    row[i] = '.';
                    row[last-1]= '#';
                    last = last-1;
                }
            }
        }

        vector<vector<char>> result(n,vector<char>(m,'.'));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                result[j][i] = boxGrid[i][j];
            }
        }
        for(auto &row : result)reverse(row.begin(),row.end());
        return result;
    }
};