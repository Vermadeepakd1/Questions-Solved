class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int i = 0; i<n-k+1; i++){
            mini = min(mini, nums[i+k-1]-nums[i]);
        }
        return mini;
    }
};