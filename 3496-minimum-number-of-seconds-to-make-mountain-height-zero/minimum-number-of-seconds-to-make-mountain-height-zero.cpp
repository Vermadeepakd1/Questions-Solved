class Solution {
    bool ispossible(int mountainHeight, vector<int>& workerTimes, long long maxt) {

        for (int t : workerTimes) {
            long long x = (-1.0 + sqrt(1.0 + 8.0 * maxt / t)) / 2.0;
            mountainHeight -= x;

            // cout << " " << t << " " << i << endl;
            if (mountainHeight <= 0)
                return true;
        }
        if (mountainHeight <= 0)
            return true;
        return false;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e16;
        long long result = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (ispossible(mountainHeight, workerTimes, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};