class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int oxs = points[0][0], oxe = points[0][1], cnt = 1;

        for(int i = 1; i<points.size(); i++){
            int cxs = points[i][0], cxe = points[i][1];

            if(cxs <= oxs || oxe >= cxs){
                oxs = max(oxs,cxs);
                oxe = min(oxe,cxe);
            }
            else{
                oxs = cxs;
                oxe = cxe;
                cnt++;
            }
        }
        return cnt;
    }
};