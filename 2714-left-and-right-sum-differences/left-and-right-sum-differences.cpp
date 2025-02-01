class Solution
{
    public:
        vector<int> leftRightDifference(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> leftsum(n, 0);
            vector<int> rightsum(n, 0);
            for (int i = 1; i < n; i++)
            {
                leftsum[i] = leftsum[i - 1] + nums[i - 1];
                rightsum[n - i - 1] = rightsum[n - i] + nums[n - i];
            }
            for (int i = 0; i < n; i++)
            {
                nums[i] = abs(leftsum[i] - rightsum[i]);
            }
            return nums;
        }
};