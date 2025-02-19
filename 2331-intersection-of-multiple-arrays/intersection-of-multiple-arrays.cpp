class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for (auto arr : nums) {
            for (int i = 0; i < arr.size(); i++) {
                mp[arr[i]]++;
            }
        }
        for (auto it : mp) {
            if (it.second == nums.size()) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};