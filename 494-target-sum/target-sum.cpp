class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) 
            return 0;
        int diff = sum - target;
        if (diff & 1)
            return 0;
        int req = diff / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int i : nums) {
            for (int j = req; j >= 0; j--) {
                if (j - i >= 0)
                    dp[j] += dp[j - i];
            }
        }
        return dp[req];
    }
};