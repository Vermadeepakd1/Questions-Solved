class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx ;
        if(x1 > xCenter)nx = x1;
        else if(x2 < xCenter)nx=x2;
        else nx = xCenter;

        int ny;
        if(y1 > yCenter)ny = y1;
        else if(y2 < yCenter)ny = y2;
        else ny = yCenter;

        int dist2 = (ny-yCenter)*(ny-yCenter) + (nx-xCenter)*(nx-xCenter);
        int r2 = radius * radius;

        return dist2 <= r2;
    }
};