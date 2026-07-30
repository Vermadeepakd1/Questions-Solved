class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;

        for (int c = 0; c <= j; c++) {
            if(i>j)break;
            if (nums[c] == 0) {
                swap(nums[c], nums[i]);
                i++;
            } else if (nums[c] == 2) {
                swap(nums[c], nums[j]);
                j--;
                c--;
            }
        }
    }
};