class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        vector<vector<int>> result;
        for (auto &vec1 : intervals) {
            int a = vec1[0], b = vec1[1];
            bool contain = false;
            for (auto &vec2 : result) {
                int c = vec2[0], d = vec2[1];
                if (c <= a && b <= d) {
                    contain = true;
                    break;
                }
            }
            if(!contain)result.push_back({a,b});
        }
        return result.size();
    }
};