class Solution
{
    public:
        bool areAlmostEqual(string s1, string s2)
        {
            int n = s1.length();
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    swap(s1[i], s1[j]);
                    if (s1 == s2)
                    {
                        return true;
                    }
                    swap(s1[i], s1[j]);
                }
            }
            return false;
        }
};