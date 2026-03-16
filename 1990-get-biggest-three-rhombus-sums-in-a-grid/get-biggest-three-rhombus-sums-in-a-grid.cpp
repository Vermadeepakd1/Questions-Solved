class Solution {
    int findarea(vector<vector<int>>& grid, int x, int y, int side) {
        int n = grid.size();

        int extra = (side - 1) * 2;
        if (y - extra < 0 || x - extra / 2 < 0 || x + extra / 2 >= n)
            return 0;
        int i = x, j = y;
        int sum = 0;
        if (extra == 0)
            sum += grid[i][j];
        for (int l = 0; l < side - 1; l++) {
            i--;
            j--;
            sum += grid[i][j];
        }
        for (int l = 0; l < side - 1; l++) {
            i++;
            j--;
            sum += grid[i][j];
        }
        for (int l = 0; l < side - 1; l++) {
            i++;
            j++;
            sum += grid[i][j];
        }
        for (int l = 0; l < side - 1; l++) {
            i--;
            j++;
            sum += grid[i][j];
        }
        return sum;
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq; // area,x,y,side
        set<int> st;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int len = 1; len <= min(i, j) + 1; len++) {
                    int a = findarea(grid, i, j, len);
                    cout << a << endl;
                    if (!st.count(a)) {
                        st.insert(a);
                        pq.push(a);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < 3; i++) {
            if (!pq.empty()) {
                int a = pq.top();
                pq.pop();
                result.push_back(a);
            }
        }
        return result;
    }
};