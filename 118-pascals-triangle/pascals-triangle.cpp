class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        vector<int> temp;
        for(int i = 1; i < numRows; i++){
            for(int j = 0; j<=i; j++){
                if( (j == 0) || (j == i) ){
                    temp.push_back(1);
                }else{
                    temp.push_back(result[i-1][j-1] 
                    + result[i-1][j]);
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};