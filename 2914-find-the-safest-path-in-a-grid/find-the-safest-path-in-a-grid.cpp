class Solution {
public:

    int findmindist(int x, int y , vector<vector<int>>&ts){
        int mini = INT_MAX;
        for(auto &v : ts){
            mini = min(mini, (abs(v[0]-x) + abs(v[1]-y)) );
        }
        cout << x << " " << y << " " << mini << endl;
        return mini;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ts;

        if(grid[0][0]==1 || grid[n-1][n-1]==1)return 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1)ts.push_back({i,j});
            }
        }

        priority_queue<vector<int>> pq;

        vector<vector<bool>>visited(n,vector<bool>(n,false));

        visited[0][0] = true;
        int dist = findmindist(0,0, ts);
        pq.push({dist,0,0});

        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!pq.empty()){
            vector<int>v = pq.top();
            pq.pop();

            int val = v[0],cx=v[1],cy=v[2];
            if(cx == n-1 && cy ==n-1)return val;

            for(auto &d : dir){
                int x = d[0], y = d[1];
                if(cx +x >=0 && cx+x < n && cy+y >=0 && cy+y <n && !visited[cx+x][cy+y]){
                    visited[cx+x][cy+y] = true;
                    int nscore = findmindist(cx+x,cy+y, ts);
                    pq.push({min(val,nscore), cx+x, cy+y});
                }
            }
        }
        return 0;
    }
};