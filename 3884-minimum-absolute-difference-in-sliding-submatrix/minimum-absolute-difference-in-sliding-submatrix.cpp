class Solution {
    int calculate(vector<vector<int>>& grid, int x, int y, int k) {
        set<int> temp;
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                temp.insert(grid[i][j]);
            }
        }

        int mini = INT_MAX;
        if (temp.size() == 1)
            mini = 0;
        else {
            int last = *temp.begin();
            auto it = temp.begin();
            it++;
            while(it!= temp.end()){
                int num = *it;
                mini = min(mini, num-last);
                last = num;
                it++;
            }
        }
        return mini;
    }

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> result;
        for (int i = 0; i <= m - k; i++) {
            vector<int> temp;
            for (int j = 0; j <= n - k; j++) {
                temp.push_back(calculate(grid, i, j, k));
            }
            result.push_back(temp);
        }
        return result;
    }
};