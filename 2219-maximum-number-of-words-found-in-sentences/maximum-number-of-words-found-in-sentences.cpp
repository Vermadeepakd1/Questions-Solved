class Solution
{
    public:
        int mostWordsFound(vector<string> &sentences)
        {
            int maxi = 0;
            for (auto sent: sentences)
            {
                int cnt = 1;
                for (int i = 0; i < sent.length(); i++)
                {
                    if (sent[i] == ' ')
                    {
                        cnt++;
                    }
                }
                maxi = max(cnt, maxi);
            }
            return maxi;
        }
};