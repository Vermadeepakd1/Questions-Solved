class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dist(1001, 0);

        for (auto i : trips) {
            int p = i[0];
            int s = i[1], e = i[2];

            dist[s] += p;
            dist[e] -= p;
        }

        for (int i = 0; i < 1001; i++) {
            if (i != 0) {
                dist[i] = dist[i] + dist[i - 1];
            }

            if (dist[i] > capacity)
                return false;
        }
        return true;
    }
};