class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if(buildings.size() <=4 )return 0;

        unordered_map<int,int> maxx,minx,maxy,miny;

        for(auto &b : buildings){
            maxx[b[1]] = max(maxx[b[1]],b[0]);
            maxy[b[0]] = max(maxy[b[0]],b[1]);
            if(minx.find(b[1]) != minx.end()){
                minx[b[1]] = min(minx[b[1]], b[0] );
            }else{
                minx[b[1]] = b[0];
            }

            if(miny.find(b[0]) != miny.end()){
                miny[b[0]] = min(miny[b[0]], b[1] );
            }else{
                miny[b[0]] = b[1];
            }
        }

        int cnt = 0;
        for(auto &b : buildings){
            if(maxx[b[1]] > b[0] && minx[b[1]] < b[0] && maxy[b[0]] > b[1] && miny[b[0]] < b[1])cnt++;
        }

        return cnt;
    }
};