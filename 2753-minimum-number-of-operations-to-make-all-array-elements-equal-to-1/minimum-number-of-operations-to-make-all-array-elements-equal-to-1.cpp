class Solution {
public:
    int minOperations(vector<int>& nums) {
        int g = gcd(nums[0], nums[1]);
        int ones = 0;
        for (int i = 2; i < nums.size(); i++) {
            g = gcd(g, nums[i]);
        }
        for (auto i : nums)
            if (i == 1)
                ones++;

        if (ones == nums.size())
            return 0;
        if (ones > 0)
            return nums.size() - ones;
        int ans = INT_MAX;
        if (g > 1)
            return -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            for (int j = i; j < n; j++) {
                curr = gcd(curr, nums[j]);
                if (curr == 1) {
                    ans = min(ans, j - i + (n - 1));
                    break;
                }
            }
        }
        return ans;
    }
};