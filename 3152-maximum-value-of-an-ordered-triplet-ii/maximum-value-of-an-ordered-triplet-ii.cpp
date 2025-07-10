class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> prefixMax(n,0), suffixMax(n,0);
        int pre = 0, suff = 0;
        for(int i = 0; i<n; i++){
            pre = max(pre,nums[i]);
            prefixMax[i] = pre;

            suff = max(suff,nums[n-i-1]);
            suffixMax[n-i-1]  = suff;
        }

        for(int j = 1; j<n-1; j++){
            long long curr = (prefixMax[j-1] - nums[j]) * suffixMax[j+1];
            ans = max(ans,curr);
        }
        return ans;
    }
};