class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1];

        vector<vector<int>> result;
        bool inserted = false;
        for (auto& v : intervals) {
            int s = v[0], e = v[1];
            if (!inserted && end < s) {
                result.push_back({start, end});
                inserted = true;
            }
            if (e < start || s> end)
                result.push_back(v);
            else if ((start >= s && start <= e) || (end >= s && end <= e)) {
                start = min(start, s);
                end = max(end, e);
            }
        }
        if(!inserted)result.push_back({start,end});
        return result;
    }
};