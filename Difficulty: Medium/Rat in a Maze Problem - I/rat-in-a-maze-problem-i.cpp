#include<bits/stdc++.h>
using namespace std;
class Solution {
    void findallpaths(vector<vector<int>>& maze, vector<vector<bool>> &visited, int n,
    vector<string> &paths, string currpath, int row, int col){
        if(row == n-1 && col == n-1) {
            paths.push_back(currpath);
            return;
        }
        visited[row][col] = true;
        //right
        if(col +1 <n && maze[row][col+1] == 1 && visited[row][col+1] == false){
            currpath += 'R';
            findallpaths(maze,visited,n, paths,currpath,row,col+1);
            currpath.pop_back();
        }
        
        //down
        if(row +1 <n && maze[row+1][col] == 1 && visited[row+1][col] == false){
            currpath += 'D';
            findallpaths(maze,visited,n, paths,currpath,row+1,col);
            currpath.pop_back();
        }
        
        //left
        if(col -1 >=0 && maze[row][col-1] == 1 && visited[row][col-1] == false){
            currpath += 'L';
            findallpaths(maze,visited,n, paths,currpath,row,col-1);
            currpath.pop_back();
        }
        
        //up
        if(row -1 >=0 && maze[row-1][col] == 1 && visited[row-1][col] == false){
            currpath += 'U';
            findallpaths(maze,visited,n, paths,currpath,row-1,col);
            currpath.pop_back();
        }
        
        visited[row][col] = false;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        vector<string> paths;
        string currpath = "";
        
        findallpaths(maze,visited,n,paths,currpath,0,0);
        sort(paths.begin(),paths.end());
        return paths;
    }
};