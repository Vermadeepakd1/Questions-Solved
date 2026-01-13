class Solution {
    pair<double,double> calcArea(vector<vector<int>>& squares, double mid){
        double a = 0, b = 0;

        for(auto &v : squares){
            double sx = v[0], sy = v[1], l = v[2];
            if(sy + l <= mid){
                b += l*l;
            }else if(sy >= mid){
                a+= l*l;
            }else{
                double areaAbove = (sy+l-mid)*l;
                double areaBelow = l*l - areaAbove;

                a+= areaAbove;
                b+=areaBelow;
            }
        }
        return {a,b};
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double s = 0, e = 2e9;
        while(e - s > 1e-5){
            double mid = s + (e-s)/2;

            auto areas = calcArea(squares, mid);
            double a = areas.first;
            double b = areas.second;

            if(a > b){
                s = mid; 
            } else {
                e = mid; 
            }
        }
        return e;
    }
};