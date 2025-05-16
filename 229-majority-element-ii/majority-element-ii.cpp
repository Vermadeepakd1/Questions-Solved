class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int target = (nums.size()/3)+1;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto it: mp){
            if(it.second >= target ){
                result.push_back(it.first);
            }
        }
        return result;
    }
};