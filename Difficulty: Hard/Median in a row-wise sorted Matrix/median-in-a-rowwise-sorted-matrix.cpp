// User function template for C++

class Solution {
    int ub(vector<int> &mat, int x, int n){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mat[mid] <= x){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // number of elements <= x
}
    
    int countse(vector<vector<int>> &mat, int m, int n, int x){
        int cnt = 0;
        for(int i =0; i<m; i++){
            cnt += ub(mat[i],x,n);
        }
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int high = INT_MIN, low = INT_MAX;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                high = max(high,mat[i][j]);
                low = min(low,mat[i][j]);
            }
        }
        
        int req = (n*m)/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int se = countse(mat,m,n,mid);
            if(se <= req)
            {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
