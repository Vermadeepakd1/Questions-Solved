class Solution {
    vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {1, 1},  {0, 1},
                                      {-1, 1},  {1, 0},  {1, -1}, {0, -1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;
        queue<pair<int, int>> q;
        q.push({0, 0});

        int steps = 1;
        grid[0][0] = 1;
        while (!q.empty()) {
            int x = q.size();

            for (int i = 0; i < x; i++) {
                auto p = q.front();
                q.pop();
                int r = p.first, c = p.second;

                for(int i=0; i<8; i++){
                    int newr = r + directions[i][0];
                    int newc = c + directions[i][1];

                    if(newr == n-1 && newc == n-1)return steps+1;

                    if(newr >= 0 && newr < n && newc >=0 && newc < n && grid[newr][newc] == 0){
                        q.push({newr,newc});
                        grid[newr][newc] = 1;
                    }
                }

                
            }
            steps++;
        }

        return -1;
    }
};