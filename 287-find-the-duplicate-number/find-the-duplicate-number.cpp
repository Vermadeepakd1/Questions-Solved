class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n,0);
        int ans = -1;
        for(int num : nums){
            cnt[num]++;
            if(cnt[num] == 2){
                ans = num;
                break;
            }
        }
        return ans;
    }
};