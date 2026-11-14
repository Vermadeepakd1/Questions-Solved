class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int sum = 0;
            for(int j = i; j < i+r && j<n; j++){
                sum += nums[j];
                if(j >= i+l-1 && sum >0){
                    mini = min(mini, sum);
                }
            }
        }
        if(mini == INT_MAX)return -1;
        return mini;
    }
};