class Solution {
    // can also be done with 2ptr approach
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            long long allowedMaximum = 1ll * nums[i] * k;
            auto it = upper_bound(nums.begin(), nums.end(), allowedMaximum);
            int idx = it - nums.begin();

            mini = min(i + (n - idx), mini);
        }
        return mini;
    }
};