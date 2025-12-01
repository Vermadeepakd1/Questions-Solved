class Solution {
    int robhouse(vector<int>& nums,int s, int e){
        int prev1 = 0,prev2 = 0;
        prev1 = nums[s];
        for(int i = s+ 1; i <=e; i++){
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];

        return max(robhouse(nums,0,n-2), robhouse(nums,1,n-1));
    }
};