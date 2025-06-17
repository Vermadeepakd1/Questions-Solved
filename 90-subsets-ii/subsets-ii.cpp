class Solution {
    void findSubset(int idx, int n, set<vector<int>> &result, vector<int> curr, vector<int>& nums){
        if(idx == n){
            sort(curr.begin(),curr.end());
            result.insert(curr);
            return;
        }
        //exclude
        findSubset(idx+1, n, result, curr, nums);
        //include
        curr.push_back(nums[idx]);
        findSubset(idx+1, n, result , curr, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        int n = nums.size();
        set<vector<int>> result;
        findSubset(0,n,result,curr,nums);
        vector<vector<int>> finalAns(result.begin(),result.end());
        return finalAns;
    }
};