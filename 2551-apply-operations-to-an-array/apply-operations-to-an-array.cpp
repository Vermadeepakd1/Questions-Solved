class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Merge adjacent equal elements
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move all zeros to the end using a two-pointer technique
        int insertPos = 0;  // Points to where the next non-zero element should go
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insertPos]);
                insertPos++;
            }
        }

        return nums;
    }
};
