class Solution {
public:

    int n ;
    vector<int> dp;

    int solve(vector<int>&arr, int idx, int d){
        int result = 1;
        if(dp[idx] != -1)return dp[idx];
        for(int i = idx-1; i>=max(0,idx-d); i--){
            if(arr[i] >= arr[idx])break;
            result  = max(result,1+solve(arr,i,d));
        }

        for(int i = idx+1; i<= min(n-1,idx+d); i++){
            if(arr[i] >= arr[idx])break;
            result  = max(result,1+solve(arr,i,d));
        }
        return dp[idx] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int result =1;
        dp.resize(n+1,-1);
        for(int i = 0; i<n; i++){
            result = max(result,solve(arr,i,d));
        }
        return result;
    }
};