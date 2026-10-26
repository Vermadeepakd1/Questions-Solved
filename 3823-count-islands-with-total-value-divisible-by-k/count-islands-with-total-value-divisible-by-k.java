class Solution {
    int m,n;
    int dir[] = {-1,0,1,0,-1};

    private boolean bfs(int[][] grid, int ii, int jj, int k, boolean[][] vis) {
        vis[ii][jj] = true;
        long sum = 0;

        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{ii,jj});
        
        while (!q.isEmpty()) {
            int[] pair = q.poll();
            int x = pair[0], y = pair[1];
            sum += grid[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] > 0 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.add(new int[]{nx, ny});
                }
            }
        }
        return (sum %k == 0);
    }

    public int countIslands(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] vis = new boolean[m][n];
        int cnt = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if (!vis[i][j] && grid[i][j] > 0) {
                    if (bfs(grid, i, j, k, vis)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
}