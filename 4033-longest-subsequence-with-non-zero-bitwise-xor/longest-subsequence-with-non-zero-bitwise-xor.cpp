class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        if(maxi==0)return 0;
        int x = 0;
        for(int i : nums)x^=i;

        if(x==0)return n-1;
        return n;
    }
};