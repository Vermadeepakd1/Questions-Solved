class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int timetaken = 0;

            for (int j = 0; j < m; j++) {
                timetaken = landStartTime[i] + landDuration[i];

                if (waterStartTime[j] <= timetaken) {
                    timetaken += waterDuration[j];
                } else {
                    timetaken +=
                        waterDuration[j] + waterStartTime[j] - timetaken;
                }
                result = min(result, timetaken);
                timetaken = waterStartTime[j] + waterDuration[j];

                if (landStartTime[i] <= timetaken) {
                    timetaken += landDuration[i];
                } else {
                    timetaken += landDuration[i] + landStartTime[i] - timetaken;
                }
                result = min(result, timetaken);
            }
        }
        return result;
    }
};