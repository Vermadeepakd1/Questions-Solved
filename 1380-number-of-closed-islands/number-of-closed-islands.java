class Solution {
    int m, n;
    int[] dir = new int[] { -1, 0, 1, 0, -1 };

    private boolean bfs( int[][] grid, boolean [][] vis,  int ii , int jj){
        boolean ans = true;
        Queue<int[]> queue = new ArrayDeque<>();
        queue.add(new int[]{ii,jj});
        vis[ii][jj] = true;

        while(!queue.isEmpty()){
            int[] pair = queue.poll();
            int x = pair[0], y = pair[1];
            if(grid[x][y] == 0 && (x==0 || y==0 || x==m-1||y==n-1)){
                ans = false;
                
                }
            vis[x][y] = true;

            for(int i = 0; i<4; i++){
                int nx = x+dir[i], ny = y+dir[i+1];
                if(nx >=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==0 && !vis[nx][ny]) {queue.add(new int[]{nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }

        return ans;

    }

    public int closedIsland(int[][] grid) {
        m = grid.length; n = grid[0].length;

        boolean[][] vis = new  boolean[m][n];
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0 && !vis[i][j] && bfs(grid,vis,i,j))ans++;
            }
        }
        return ans;
    }
}