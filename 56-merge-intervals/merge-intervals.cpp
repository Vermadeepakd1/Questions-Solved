class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i =0; i<n; i++){
            if(i == n-1){
                end = max(intervals[i][1],end);
                result.push_back({start,end});
                continue;
            }
            if(intervals[i+1][0] <= end){
                end = max(intervals[i+1][1],end);
            }else{
                result.push_back({start,end});
                start =intervals[i+1][0];
                end = intervals[i+1][1];
            }
        }
        return result;
    }
};