class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &groupSizes)
        {
            unordered_map<int, vector < int>> mp;
            for (int i = 0; i < groupSizes.size(); i++)
            {
                mp[groupSizes[i]].push_back(i);
            }
            vector<vector < int>> result;
            for (auto &it: mp)
            {
                vector<int> temp;
                for (int i = 0; i < it.second.size(); i++)
                {
                    if (temp.size() < it.first)
                    {
                        temp.push_back(it.second[i]);
                    }
                    if (temp.size() == it.first)
                    {
                        result.push_back(temp);
                        temp.clear();
                    }
                }
            }
            return result;
        }
};