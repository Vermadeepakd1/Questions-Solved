class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int used = 0;
        int j = 0, i = 0;
        int ans = 0;
        int n = nums.size();
        while(j<n){
            if(nums[j]==0){
                used++;
            }
            while(used > k){
                if(nums[i]==0)used--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};