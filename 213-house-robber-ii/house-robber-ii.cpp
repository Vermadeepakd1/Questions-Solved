class Solution {
    int solve(vector<int>& nums, int start){
        int n = nums.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i =1; i<=n; i++){
            dp[i][1] = dp[i-1][0] + nums[i+start-1];
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[n][0],dp[n][1]);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(solve(nums,0) ,solve(nums,1));
    }
};