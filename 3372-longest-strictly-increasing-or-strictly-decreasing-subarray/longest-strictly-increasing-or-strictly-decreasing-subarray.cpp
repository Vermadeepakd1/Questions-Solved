class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int ans = 1;
        int inclen = 1,declen =1;
        for(int i =1; i<n; i++){
            if(nums[i] > nums[i-1]){
                inclen++;
                declen =1;
            }
            else if(nums[i]<nums[i-1]){
                declen++;
                inclen = 1;
            }
            else{
                inclen = 1;
                declen = 1;
            }
            ans = max(ans,max(inclen, declen));
        }
        return ans;
    }
};