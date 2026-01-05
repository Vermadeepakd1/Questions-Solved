class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0, mini = LLONG_MAX, neg = 0;
        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                sum += abs(matrix[i][j]);
                mini = min(mini,1ll*abs(matrix[i][j]));
                if(matrix[i][j] < 0)neg++;
            }
        }

        if(neg & 1){
            sum -= 2*mini;
        }

        return sum;
    }
};