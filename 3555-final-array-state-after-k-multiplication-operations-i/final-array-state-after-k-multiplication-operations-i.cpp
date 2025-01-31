class Solution
{
    public:
        vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
        {
            int minindex = -1;
            int min = INT_MAX;
            while (k--)
            {
                min = INT_MAX;
                for (int i = 0; i < nums.size(); i++)
                {

                    if (nums[i] < min)
                    {
                        min = nums[i];
                        minindex = i;
                    }
                }
                nums[minindex] *= multiplier;
            }
            return nums;
        }
};