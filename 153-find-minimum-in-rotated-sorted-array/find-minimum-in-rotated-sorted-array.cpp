class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        int n = nums.size();
        int s = 0, e = nums.size() -1;
        while(s <=e){
            int mid = s+(e-s)/2;
            if(nums[mid] >= nums[0] &&nums[mid] >= nums[n-1]){
                s= mid+1;
            }else {
                mini = nums[mid];
                e = mid-1;
            }
        }
        return mini;
    }
};