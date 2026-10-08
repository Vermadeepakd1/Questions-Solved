class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0, e = n - 1;
        int cnt = 0;
        while (s < e) {
            if (nums[s] + nums[e] == k) {
                cnt++, s++, e--;
            } else if (nums[s] + nums[e] > k)
                e--;
            else
                s++;
        }
        return cnt;
    }
};