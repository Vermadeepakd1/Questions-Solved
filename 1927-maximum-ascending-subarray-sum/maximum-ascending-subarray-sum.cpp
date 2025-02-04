class Solution
{
    public:
        int maxAscendingSum(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 0) return 0;
            int result = 0;
            int tempsum = nums[0];
            for (int i = 1; i < n; i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    tempsum += nums[i];
                }
                else
                {
                    result = max(result, tempsum);
                    tempsum = nums[i];
                }
            }
            result = max(result, tempsum);
            return result;
        }
};