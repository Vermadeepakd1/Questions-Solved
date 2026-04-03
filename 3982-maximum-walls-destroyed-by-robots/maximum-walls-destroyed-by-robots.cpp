class Solution {
    vector<vector<int>> t;

    int countWalls(const vector<int>& walls, int l, int r) {
        if (l > r) return 0;
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        return right - left;
    }

    int solve(const vector<int>& walls, vector<pair<int, int>>& roboD,
              vector<pair<int, int>>& ranges, int i, int predir) {

        if (i == roboD.size()) return 0;
        if (t[i][predir] != -1) return t[i][predir];

        int leftStart = ranges[i].first;
        if (predir == 1) {
            leftStart = max(leftStart, roboD[i - 1].first + roboD[i - 1].second + 1);
        }
        
        int lefty = countWalls(walls, leftStart, roboD[i].first) +
                    solve(walls, roboD, ranges, i + 1, 0);

        int righty = countWalls(walls, roboD[i].first, ranges[i].second) +
                     solve(walls, roboD, ranges, i + 1, 1);

        return t[i][predir] = max(lefty, righty);
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        t.assign(n, vector<int>(2, -1));

        vector<pair<int, int>> robD(n);
        for (int i = 0; i < n; i++) {
            robD[i] = {robots[i], distance[i]};
        }

        sort(robD.begin(), robD.end());
        sort(walls.begin(), walls.end());

        vector<pair<int, int>> ranges(n);
        for (int i = 0; i < n; i++) {
            int pos = robD[i].first;
            int d = robD[i].second;

            int l = max(((i == 0) ? (int)-2e9 : robD[i - 1].first + 1), pos - d);
            int r = min(((i == n - 1) ? (int)2e9 : robD[i + 1].first - 1), pos + d);

            ranges[i] = {l, r}; 
        }

        return solve(walls, robD, ranges, 0, 0);
    }
};