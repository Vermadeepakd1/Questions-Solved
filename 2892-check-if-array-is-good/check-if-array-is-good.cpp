class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1);
        for(int i : nums){
            if(i > n)return false;
            cnt[i]++;
        }
        for(int i = 1; i<n-1; i++){
            if(cnt[i] != 1)return false;
        }
        if(cnt[n-1] != 2)return false;
        return true;
    }
};