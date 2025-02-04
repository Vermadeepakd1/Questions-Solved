class Solution
{
    public:
        vector<int> decode(vector<int> &encoded, int first)
        {
            int n = encoded.size() + 1;
            vector<int> result(n, 0);
            result[0] = first;
            for (int i = 1; i < n; i++)
            {
                result[i] = result[i - 1] ^ encoded[i - 1];
            }
            return result;
        }
};