class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a, int b){
            return abs(a) <abs(b);
        });
        int n = nums.size();
        int ans = abs(nums[n-1]) - abs(nums[2]);
        ans = min(ans, abs(nums[n-3])- abs(nums[0]));
        ans = min(ans, abs(nums[n-2]) - abs(nums[1]));
        return ans;
    }
};