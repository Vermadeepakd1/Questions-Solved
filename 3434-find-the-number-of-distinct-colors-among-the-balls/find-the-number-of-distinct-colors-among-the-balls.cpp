class Solution
{
    public:
        vector<int> queryResults(int limit, vector<vector < int>> &queries)
        {
            unordered_map<int, int> color;
            unordered_map<int, int> freq;
            vector<int> result;
            for (auto &q: queries)
            {
                int index = q[0];
                int col = q[1];

                if (color[index])
                {
                    freq[color[index]]--;
                }
                if (freq[color[index]] == 0)
                {
                    freq.erase(color[index]);
                }

                color[index] = col;
                freq[color[index]]++;
                result.push_back(freq.size());
            }
            return result;
        }
};