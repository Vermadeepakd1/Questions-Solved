class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> freeTime;
        int n = startTime.size();

        freeTime.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            int free = startTime[i] - endTime[i - 1];

            freeTime.push_back(free);
        }

        freeTime.push_back(eventTime - endTime[n - 1]);

        int maxi = 0;

        if (freeTime.size() == 0)
            return 0;
        int currsum = 0;
        
        int i = 0;
        int j = 0;
        

        int x = freeTime.size();
        while(j < x){
            currsum += freeTime[j];

            while( i < x && j-i+1 > k+1){
                currsum -= freeTime[i];
                i++;
            }

            maxi = max(maxi,currsum);
            j++;
        }

        return maxi;

    }
};