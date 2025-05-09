class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0],currsum = nums[0];
        for(int i = 1; i<n; i++){
            currsum += nums[i];
            if(nums[i] > currsum){
                currsum = nums[i];
            }
            maxsum = max(maxsum,currsum);
        }
        return maxsum;
    }
};