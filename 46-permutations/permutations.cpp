class Solution {
    void findpermute(vector<vector<int>>& result, int n, int idx,
                     vector<int>& nums) {
        if (idx == n) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            findpermute(result, n, idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        findpermute(result, n, 0, nums);
        return result;
    }
};