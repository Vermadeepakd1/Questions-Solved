class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int currx = points[0][0], curry = points[0][1];

        int steps = 0;

        for(auto &pt : points){
            int x = pt[0], y = pt[1];

            while(currx != x || curry != y){
                currx = (currx > x)?currx-1 : ((currx<x)? (currx+1):currx);
                curry = (curry > y)? curry-1 : ((curry<y)?(curry+1):curry);
                steps++;
            }

        }
        return steps;
    }
};