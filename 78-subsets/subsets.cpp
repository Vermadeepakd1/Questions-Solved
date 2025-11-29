class Solution {
    void findsubset(vector<vector<int>> &result, vector<int> temp, vector<int> &nums, int idx){
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }
        //include
        temp.push_back(nums[idx]);
        findsubset(result,temp,nums,idx+1);
        //exclude
        temp.pop_back();
        findsubset(result,temp,nums,idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        findsubset(result,temp,nums,0);
        return result;
    }
};