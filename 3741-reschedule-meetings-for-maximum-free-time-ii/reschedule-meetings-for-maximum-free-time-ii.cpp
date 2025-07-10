class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int n = startTime.size();

        freeTime.push_back(startTime[0]);

        for(int i = 1; i<n; i++){
            int free = startTime[i] - endTime[i-1];
            freeTime.push_back(free);
        }

        freeTime.push_back(eventTime - endTime[n-1]);


        int l = freeTime.size();
        vector<int> premax(l,0), postmax(l,0);
        for(int i = l-2; i >= 0; i--){
            postmax[i] = max(postmax[i+1], freeTime[i+1]);
        }

        for(int i = 1; i < l; i++){
            premax[i] = max(premax[i-1], freeTime[i-1]);
        }
        int result = 0;

        for(int i =1; i<l; i++){
            int curr = endTime[i-1] - startTime[i-1];

            if(curr <= max(premax[i-1],postmax[i])){
                result = max(result, curr + freeTime[i] + freeTime[i-1]);
            }
            result = max(result, freeTime[i] + freeTime[i-1]);
        }
        return result;
    }
};