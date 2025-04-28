class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long sum = 0;
        long long result = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            sum += nums[end];
            while ( (long long)sum * (end - start + 1) >= k ) {
                sum -= nums[start];
                start++;
            }
            result += (end - start + 1);
        }
        return result;
    }
};