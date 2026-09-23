class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int req = sum - x;

        int i = 0, j = 0;
        int curr = 0;
        int ans = INT_MAX;
        while (j < n) {
            curr += nums[j];
            while (i<=j && curr > req) {
                curr -= nums[i];
                i++;
            }
            if (curr == req)
                ans = min(ans, i + n - j -1);
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};