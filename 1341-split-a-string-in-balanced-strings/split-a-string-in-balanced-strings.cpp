class Solution
{
    public:
        int balancedStringSplit(string s)
        {
            int cnt = 0, lc = 0, rc = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'L')
                {
                    lc++;
                }
                else if (s[i] == 'R')
                {
                    rc++;
                }
                if (lc == rc)
                {
                    cnt++;
                    lc = rc = 0;
                }
            }
            return cnt;
        }
};