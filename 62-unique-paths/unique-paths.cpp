class Solution {
    int findcount(int currr, int currc, int m, int n, vector<vector<int>>&paths){
        if(currr == m-1 && currc == n-1){
            return 1;
        }
        if(currr >= m || currc >= n){
            return 0;
        }
        if(paths[currr][currc] != -1){
            return paths[currr][currc];
        }
        return paths[currr][currc] = findcount(currr,currc+1,m,n,paths) + findcount(currr+1,currc,m,n,paths);

    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>paths(m,vector<int>(n,-1));
        return findcount(0,0,m,n,paths);
    }
};