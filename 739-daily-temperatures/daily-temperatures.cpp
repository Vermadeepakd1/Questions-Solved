class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> result;

        stack<pair<int, int>> st;

        int n = t.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second <= t[i])
                st.pop();
            if (st.empty())
                result.push_back(0);
            else {
                result.push_back({st.top().first - i});
            }
            st.push({i, t[i]});
        }
        reverse(result.begin(), result.end());
        return result;
    }
};