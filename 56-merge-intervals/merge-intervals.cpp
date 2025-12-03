class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        int s = intervals[0][0],e = intervals[0][1];
        int n = intervals.size();
        for(int i =1; i<n; i++){
            auto curr = intervals[i];

            if(curr[0] > e){
                ans.push_back({s,e});
                s = curr[0];
                e = curr[1];
            }else {
                e = max(curr[1],e);
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};