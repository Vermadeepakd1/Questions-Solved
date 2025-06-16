class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, mini = nums[0];

        for(int i = 0; i<n-1; i++){
            mini = min(mini,nums[i]);
            ans = max(ans, nums[i+1]-mini);
        }

        if(ans <= 0) return -1;

        return ans;
    }
};