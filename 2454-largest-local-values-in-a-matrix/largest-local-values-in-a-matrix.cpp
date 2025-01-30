class Solution
{
    public:
        vector<vector < int>> largestLocal(vector<vector < int>> &grid)
        {
            int n = grid.size();
            vector<vector < int>> result(n - 2, vector<int> (n - 2, 0));
            for (int i = 0; i < n - 2; i++)
            {
                for (int l = 0; l < n - 2; l++)
                {

                    int temp = -1;
                    for (int j = i; j <= i + 2; j++)
                    {
                        for (int k = l; k <= l + 2; k++)
                        {
                            temp = max(temp, grid[j][k]);
                        }
                    }
                result[i][l] = temp;
                }
            }
            return result;
        }
};