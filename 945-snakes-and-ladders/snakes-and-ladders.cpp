class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<pair<int, int>> q; // x,y,steps
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [place, steps] = q.front();
            q.pop();

            // int x = (val+n-1) / n;
            // x--;
            // int y = (x&1)? n-(val-x*n):  val-x*n   ;
            if (place == n * n)
                return steps;

            for (int i = 1; i <= 6; i++) {
                int val = place + i;
                if (val > n * n)
                    continue;

                int idx = val - 1;
                int x = idx / n;
                int y = (x % 2 == 0) ? (idx % n) : (n - 1 - (idx % n));
                x = n - 1 - x;

                if (board[x][y] == -1) {
                    if (!visited[val]) {
                        visited[val] = true;
                        q.push({val, steps + 1});
                    }
                } else {
                    if (!visited[board[x][y]]) {
                        visited[board[x][y]] = true;
                        q.push({board[x][y], steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};