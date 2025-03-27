class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int x = -1,f = -1;
        for(auto it: mp){
            if(it.second > f){
                f = it.second;
                x = it.first;
            }
        }
        vector<int> prefix(n);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == x){
                cnt++;
            }
            prefix[i] = cnt;
        }
        for(int i = 0; i<=n-2; i++){
            int f1 = 0, f2 = 0;
            f1= prefix[i];
            f2 = f - f1;
            if(f1*2 > i+1  && f2*2 > n-(i+1) ){
                return i;
            }
        }
        return -1;
    }
};