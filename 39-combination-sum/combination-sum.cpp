class Solution {
    void findCombinations(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                findCombinations(candidates, target - candidates[i], i, temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombinations(candidates, target, 0, temp, ans);
        return ans;
    }
};
