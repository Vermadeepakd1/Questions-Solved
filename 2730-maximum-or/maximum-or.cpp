class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0), suffix(n, 0);
        long long curror = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = curror;
            curror = curror | nums[i];
        }
        curror = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = curror;
            curror = curror | nums[i];
        }
        long long maxor = 0, newnum = 0;
        for (int i = 0; i < n; i++) {
            newnum = nums[i];
            newnum = (long long)newnum << k;
            maxor = max(maxor, newnum | prefix[i] | suffix[i]);
        }
        return maxor;
    }
};
