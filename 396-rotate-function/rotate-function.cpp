class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long totalSum = 0;
        long long F = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            F += (long long)i * nums[i]; 
        }

        long long maxi = F;

        for(int i = 1; i < n; i++) {
            F = F + totalSum - n * nums[n - i]; 
            maxi = max(maxi, F);
        }

        return (int)maxi;
    }
};