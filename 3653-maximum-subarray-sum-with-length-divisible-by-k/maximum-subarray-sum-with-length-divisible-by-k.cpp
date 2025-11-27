class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> min_prefix(k,LLONG_MAX);
        min_prefix[0] = 0;
        long long max_sum = -LLONG_MAX;
        long long current = 0;

        for(int i = 0; i<n; i++){
            current += nums[i];

            int rem = (i+1)%k;

            if(min_prefix[rem] != LLONG_MAX){
                max_sum = max(max_sum , current-min_prefix[rem]);
            }

            min_prefix[rem] = min(min_prefix[rem],current);


        }

        return max_sum;
    }
};