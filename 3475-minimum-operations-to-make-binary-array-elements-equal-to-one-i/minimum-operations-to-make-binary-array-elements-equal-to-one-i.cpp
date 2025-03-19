class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                count++;
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = (nums[i + j] == 0) ? 1 : 0;
                }
            }
        }
        if (nums[n - 2] != 1 || nums[n - 1] != 1) {
            return -1;
        }
        return count;
    }
};