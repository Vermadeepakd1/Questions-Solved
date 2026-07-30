class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows,cols;

        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] ==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for(int i : cols){
            for(int j = 0;  j < m; j++){
                matrix[j][i] = 0;
            }
        }

        for(int i : rows){
            for(int j = 0; j<n; j++){
                matrix[i][j] = 0;
            }
        }

    }
};