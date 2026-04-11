class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i  = 0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &it : mp){
            vector<int> arr = it.second;
            if(arr.size()   >= 3){
                for(int i = 0; i<arr.size()-2; i++){
                    ans =  min(ans, 2*(arr[i+2]-arr[i]));
                }
            }
        }
        return (ans == INT_MAX)?-1 : ans;
    }
};