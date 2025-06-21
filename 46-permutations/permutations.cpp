class Solution {
    void findPermute(int n, vector<vector<int>>& result, vector<int>& temp,
                     unordered_map<int, bool>& visited, vector<int>& nums) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                findPermute(n, result, temp, visited, nums);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> visited;
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;

        findPermute(n, result, temp, visited, nums);

        return result;
    }
};