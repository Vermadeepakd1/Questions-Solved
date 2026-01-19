class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int l = 1;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> rpsum(n,vector<int>(m));
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<m; j++){
                sum += mat[i][j];
                rpsum[i][j] = sum;
            }
        }
        int ans = 0;

        for(int size = 1; size <= min(n,m); size++){
            bool found =false;
            for(int i = 0; i< n-size+1; i++){
                for(int j = 0; j<m-size+1; j++){
                    int temp = 0;
                    for(int row = i; row < i+size; row++){    
                        temp += rpsum[row][j+size-1] -( (j-1 >= 0)?rpsum[row][j-1]:0 );
                    }
                    if(temp <= threshold){
                        ans = size;
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(!found)break;
        }
        return ans;
    }
};