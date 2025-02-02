class Solution
{
    public:
        vector<int> smallerNumbersThanCurrent(vector<int> &nums)
        {
            vector<int> temp = nums;
            vector<int> result;
            sort(temp.begin(), temp.end());
            for (int i = 0; i < nums.size(); i++)
            {
                int j = 0;
                while (temp[j] < nums[i])
                {
                    j++;
                }
                result.push_back(j);
            }
            return result;
        }
};