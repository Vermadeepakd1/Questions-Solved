class Solution {
    int findi(vector<int>& nums, int n, int target) {
        int s = 0;
        int e = min((int)nums.size() - 1, n);
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int i = findi(nums1, j, nums2[j]);
            if (i != -1) {
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};