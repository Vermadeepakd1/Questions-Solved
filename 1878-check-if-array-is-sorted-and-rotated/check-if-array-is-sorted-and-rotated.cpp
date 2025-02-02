class Solution
{
    public:
        bool check(vector<int> &nums)
        {
            int n = nums.size();
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] <= nums[(j + 1) % n])
                {
                    continue;
                }
                else
                {
                    count++;
                }
            }
            if (count <= 1)
                return true;
            return false;
        }
};