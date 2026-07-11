class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<int>>& grid, unordered_map<int, int>& islandsize,
             int islandnum, int n, int i, int j) {
        // grid[i][j] = islandnum;
        // islandsize[islandnum]++;

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = islandnum;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            
            islandsize[islandnum]++;

            for (auto& d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[nx][ny] == 1) {
                        grid[nx][ny] = islandnum;
                    q.push({nx, ny});
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        // unordered_map<pair<int>,int> belongtoisland;
        unordered_map<int, int> islandsize;
        int currisland = 2;

        int n = grid.size();
        // vector<vector<bool>> visited(n,vector<bool>(n,false));

        set<pair<int, int>> zeros;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    zeros.insert({i, j});
                    continue;
                } else {
                    if (grid[i][j] == 1) {
                        bfs(grid, islandsize, currisland++, n, i, j);
                    }
                }
            }
        }

        if(zeros.size()==0)return n*n;
        int result = 0;
        for (auto [x, y] : zeros) {
            int left = 0, right = 0, up = 0, down = 0;
            set<int> st;
            if (y != 0 && !st.count(grid[x][y - 1])) {
                left = islandsize[grid[x][y - 1]];
                st.insert(grid[x][y - 1]);
            }
            if(y!=n-1 && !st.count(grid[x][y + 1]) ){
                 right =  islandsize[grid[x][y + 1]];
                 st.insert(grid[x][y + 1]);
            }
            if(x != 0 && !st.count(grid[x - 1][y])){
                up = islandsize[grid[x - 1][y]];
                st.insert(grid[x - 1][y]);
            }
            if(x!=n-1  && !st.count(grid[x + 1][y])){
                down = islandsize[grid[x + 1][y]];
                st.insert(grid[x + 1][y]);
            }

            result = max(result, 1 + left + right + up + down);
        }
        return result;
    }
};