class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            bool left = (mid==0 || nums[mid-1] < nums[mid]);
            bool right = (mid==n-1 || nums[mid+1] < nums[mid]);
            if(left && right)return mid;
            else if(!left)e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
};