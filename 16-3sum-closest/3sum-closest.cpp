class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int result = -1;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    result = sum;
                }
                if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};