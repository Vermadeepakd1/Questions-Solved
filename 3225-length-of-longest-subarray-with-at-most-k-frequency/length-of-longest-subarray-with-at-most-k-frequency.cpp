class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int j = 0, i=0;
        int n = nums.size();

        int maxi = 0;

        while(j <n){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            int len = j-i+1;
            maxi = max(maxi,len);

            j++;
        }
        return maxi;
    }
};