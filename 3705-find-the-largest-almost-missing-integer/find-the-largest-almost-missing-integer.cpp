class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = -1;
        
        for(int i : nums){
            mp[i]++;
        }
        int start = nums[0], end = nums[n-1];
        if(k == 1){
            for(auto [key,val]: mp){
                if(val == 1){
                    ans =max(ans,key);
                }
            }
        }else if(k==n){
            ans = *max_element(nums.begin(),nums.end());
        }else{
            if(mp[start] == 1)ans = max(ans,start);
            if(mp[end]==1)ans = max(ans,end);
        }
        return ans;
    }
};