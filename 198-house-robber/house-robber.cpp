class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int prev1 = 0,prev2 = 0;
        if(n == 0) return 0;
        prev1 = nums[0];
        for(int i = 1; i <n; i++){
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};