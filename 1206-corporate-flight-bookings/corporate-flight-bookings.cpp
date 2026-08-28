class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (auto& b : bookings) {
            int u = b[0] - 1, v = b[1], c = b[2];
            ans[u] += c;
            if (v < n)
                ans[v] -= c;
        }
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};