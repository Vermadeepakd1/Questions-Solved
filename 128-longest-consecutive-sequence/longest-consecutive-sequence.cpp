class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            unordered_set<int> st(nums.begin(), nums.end());
            int ans = 0;
            for (int num: st)
            {
                int count = 0;
                if (st.find(num - 1) == st.end())
                {
                    int curr = num;
                    while (st.find(curr) != st.end())
                    {
                        count++;
                        curr++;
                    }
                    ans = max(ans, count);
                }
            }
            return ans;
        }
};