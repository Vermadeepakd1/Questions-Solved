class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxi = 1;
        for(int i = 0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j<n;j++){
                int x2 = points[j][0], y2 = points[j][1];
                double m = 1.0*(y2-y1)/(x2-x1);
                int cnt = 2;
                for(int k = 0;k<n; k++){
                    if(k==i || k==j)continue;
                    int x3 = points[k][0], y3=points[k][1];
                    double m2 = 1.0 * (y3-y2)/(x3-x2);
                    if(m2==m)cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};