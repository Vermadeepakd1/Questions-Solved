class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = (nums.size()/2)+1;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
            if(mp[num] == target){
                return num;
            }
        }
        return -1;
    }
};