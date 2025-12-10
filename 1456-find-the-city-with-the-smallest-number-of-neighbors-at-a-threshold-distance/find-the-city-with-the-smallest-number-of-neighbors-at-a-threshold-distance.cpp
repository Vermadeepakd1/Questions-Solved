class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto& vec : edges) {
            dist[vec[0]][vec[1]] = vec[2];
            dist[vec[1]][vec[0]] = vec[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = 0;
        int minReach = INT_MAX;
        for(int i = 0; i<n; i++){
            int reach = 0;
            for(int j = 0; j<n;j++){
                if(dist[i][j] <= distanceThreshold){
                    reach++;
                }
            }
            if(reach <= minReach){
                minReach = reach;
                ans = i;
            }
        }
        return ans;
    }
};