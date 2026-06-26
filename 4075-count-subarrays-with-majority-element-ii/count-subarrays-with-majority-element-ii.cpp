class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        int cumsum = 0;
        mp[0]=1;

        long long validleft = 0;
        long long result = 0;

        for(int j = 0; j<nums.size(); j++){
            if(nums[j] == target){
                validleft += mp[cumsum];
                cumsum += 1;
            }else{
                cumsum -=1;
                validleft -= mp[cumsum];
            }

            mp[cumsum] += 1;
            result += validleft;
        }
        return result;
    }
};