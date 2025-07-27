class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int last = nums[0];
        for(int i = 1; i < n-1; i++){
            if ( (nums[i] >= last && nums[i] <= nums[i+1]) || ( nums[i] <= last && nums[i] >= nums[i+1] ) ){
                continue;
            }else{
                last = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};