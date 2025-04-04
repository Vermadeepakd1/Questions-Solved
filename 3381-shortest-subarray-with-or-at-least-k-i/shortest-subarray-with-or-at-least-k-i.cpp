class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int myor = 0;
            for (int j = i; j < n; j++) {
                myor |= nums[j];
                if (myor >= k) {
                    ans = min(ans, j - i + 1);
                    break; 
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
