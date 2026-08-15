class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[n-1]==0)return 0;
        int x = 0;
        for(int i : nums)x^=i;

        if(x==0)return n-1;
        return n;
    }
};