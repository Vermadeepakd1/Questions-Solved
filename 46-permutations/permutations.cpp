class Solution {
    void findPermute(vector<int> nums, vector<vector<int>>& result, int idx) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = idx; i< nums.size(); i++){
            swap(nums[idx],nums[i]);
            findPermute(nums,result,idx+1);
            swap(nums[idx],nums[i]);
        }
        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int idx= 0;

        findPermute(nums, result, idx);

        return result;
    }
};