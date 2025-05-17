class Solution {
public:
    int merge(vector<int>& nums, int start, int mid, int end) {
        int cnt = 0;
        int j = mid + 1;

        // Count important reverse pairs
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }


        int left = start;
        int right = mid + 1;
        vector<int> newarr;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                newarr.push_back(nums[left++]);
            } else {
                newarr.push_back(nums[right++]);
            }
        }
        while (left <= mid) {
            newarr.push_back(nums[left]);
            left++;
        }
        while (right <= end) {
            newarr.push_back(nums[right]);
            right++;
        }
        for (int i = start; i <= end; i++) {
            nums[i] = newarr[i - start];
        }
        return cnt;
    }
    void mergesort(vector<int> &nums, int start, int end, int& count) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid, count);
        mergesort(nums, mid + 1, end, count);
        count += merge(nums, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergesort(nums, 0, n - 1, count);
        return count;
    }
};