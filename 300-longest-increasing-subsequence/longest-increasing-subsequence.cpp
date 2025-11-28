class Solution {
    int dp[2501][2501];
    int solve(vector<int>& nums, int idx, int p){
        if(idx >= nums.size())return 0;
        if(p!= -1 && dp[idx][p] != -1)return dp[idx][p];
        int take = 0, skip = 0;
        //take
        if(p == -1 || nums[idx] > nums[p]){
            take = 1 + solve(nums,idx+1,idx);
        }
        //skip
        skip = solve(nums,idx+1,p);

        if(p!= -1){
            dp[idx][p] = max(take,skip);
        }
        return  max(take,skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};