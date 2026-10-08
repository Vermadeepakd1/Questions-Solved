class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j<n && nums[j] != 0)
            j++;
        i = j;
        while (i < n) {
            while (j < n && nums[j] != 0)
                j++;
            while (i < n && nums[i] == 0)
                i++;
            if (i < n && j < n)
                swap(nums[i], nums[j]);
        }
    }
};