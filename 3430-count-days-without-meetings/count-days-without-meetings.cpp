class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());
        int cnt = 0, lastEnd = 0;

        for (auto& m : meetings) {
            int start = m[0], end = m[1];
            if (start > lastEnd + 1) {
                cnt += start - lastEnd - 1;
            }
            lastEnd = max(lastEnd, end);
        }
        if (lastEnd < days) {
            cnt += days - lastEnd;
        }
        return cnt;
    }
};