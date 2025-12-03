class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;

        int news = newInterval[0], newe = newInterval[1];
        bool placed = false;

        for (auto i : intervals) {
            int s = i[0];
            int e = i[1];

            if (e < news) {
                result.push_back({s, e});
            } else if (s > newe) {
                if (!placed) {
                    placed = true;
                    result.push_back({news, newe});
                }
                result.push_back({s, e});

            } else {
                news = min(s, news);
                newe = max(e, newe);
            }
        }
        if (!placed) {
            placed = true;
            result.push_back({news, newe});
        }
        return result;
    }
};