class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> landendstart,landstartduration,waterendstart,waterstartduration;

        for(int i = 0; i<n; i++){
            landendstart.push_back({landStartTime[i]+landDuration[i], landStartTime[i]});
        }
        for(int i = 0; i<m; i++){
            waterendstart.push_back({waterStartTime[i]+waterDuration[i], waterStartTime[i]});
        }

        sort(landendstart.begin(),landendstart.end());
        sort(waterendstart.begin(),waterendstart.end());

        int startWithLand = 0, startWithWater = 0 ;
        startWithLand = landendstart[0].first , startWithWater = waterendstart[0].first;

        cout << startWithLand << " " << startWithWater << endl;

        int sl = INT_MAX, sw = INT_MAX;
        for(int i = 0; i<n; i++){
            if(landStartTime[i] <= startWithWater){
                sw = min(startWithWater+landDuration[i],sw);
            }else{
                sw = min(sw, landStartTime[i] + landDuration[i]);
            }
        }

        for(int i = 0; i<m; i++){
            if(waterStartTime[i] <= startWithLand){
                sl = min(startWithLand + waterDuration[i], sl);
            }else{
                sl = min(sl,waterStartTime[i]+waterDuration[i]);
            }
        }

        return min(sl,sw);
    }
};