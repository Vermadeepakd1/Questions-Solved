class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;
        for(int j = 0; j<n; j++){
            sum += nums[j];
            if(sum >= target){
                // mini = min(mini, j-i+1);
                while(sum >= target){
                    mini = min(mini, j-i+1);
                    sum -= nums[i];
                    i++;
                }
            }

        }
        return (mini == INT_MAX)?0: mini;
    }
};