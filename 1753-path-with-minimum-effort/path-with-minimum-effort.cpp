class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto top = pq.top();
            int e = top[0];
            int x = top[1];
            int y = top[2];
            pq.pop();

            if (e > effort[x][y])
                continue;

            if (x == n - 1 && y == m - 1) return e;
            for (int i = 0; i < 4; i++) {
                int newx = x + nr[i];
                int newy = y + nc[i];

                if (newx >= 0 && newy >= 0 && newx < n && newy < m ) {
                    int diff = abs(heights[x][y] - heights[newx][newy]);
                    int new_effort = max(e, diff);

                    if (new_effort < effort[newx][newy]) {
                        effort[newx][newy] = new_effort;
                        pq.push({new_effort, newx, newy});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};