class Solution {
    void findsub(int idx, int n, vector<vector<int>> &result,vector<int> temp,int target, vector<int>&candidates){
        if(target == 0){
            result.push_back(temp);
            
            return;
        }
        for(int i = idx; i<n; i++){
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                findsub(i+1,n,result,temp,target-candidates[i],candidates);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        int n = candidates.size();
        findsub(0,n,result,temp,target,candidates);
        return result;
    }
};