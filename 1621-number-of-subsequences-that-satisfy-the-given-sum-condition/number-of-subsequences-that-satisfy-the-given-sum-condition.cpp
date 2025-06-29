class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cnt = 0;
        int mod = 1e9 + 7;

        vector<int> power(n,1);

        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % mod;

        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                cnt = (cnt + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return (int)(cnt % mod);
    }
};