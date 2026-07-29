class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;

        int req = sum/2;

        vector<bool> dp(req+1,false);
        dp[0]=true;

        sort(nums.begin(),nums.end());

       for(int num : nums) {
            for(int i = req; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[req];
    }
};