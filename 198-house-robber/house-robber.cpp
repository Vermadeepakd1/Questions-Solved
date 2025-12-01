class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int> dp(n+1,-1);
        if(n == 0) return 0;
        dp[0] = nums[0];

        for(int i = 1; i <n; i++){
            dp[i] = max(dp[i-1] , ((i-2 >=0)?dp[i-2]:0) + nums[i]);
        }

        return dp[n-1];
    }
};