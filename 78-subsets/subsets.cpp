class Solution {
    void findsubsets(vector<int>& nums, vector<vector<int>> &result, vector<int> temp, int idx){
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }

        findsubsets(nums,result,temp,idx+1);
        temp.push_back(nums[idx]);
        findsubsets(nums,result,temp,idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        findsubsets(nums,result,temp,0);
        return result;
    }
};