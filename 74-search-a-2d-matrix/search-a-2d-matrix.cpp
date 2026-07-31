class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m-1;

        int row = 0;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(matrix[mid][n-1] >= target){
                row = mid;
                e = mid-1;
            }else s = mid+1;
        }

        s=0,e=n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[row][mid] > target){
                e = mid-1;
            }else if(matrix[row][mid] ==  target){
                return true;
            }else s=mid+1;
        }
        return false;
    }
};