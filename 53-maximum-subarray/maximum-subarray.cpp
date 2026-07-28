class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxi = sum;
        for(int i = 1; i<nums.size(); i++){
            sum += nums[i];
            sum = max(sum,nums[i]);
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};