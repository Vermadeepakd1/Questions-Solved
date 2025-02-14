// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 0, e = n;

        int ans = 0;
        int mid = s;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};