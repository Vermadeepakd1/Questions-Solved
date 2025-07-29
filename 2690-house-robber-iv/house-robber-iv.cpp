class Solution {
public:
    bool canpick(vector<int>&nums, int k, int mid){
        int count = 0;
        int n = nums.size();
        int i = 0;

        while(i < n){
            if(nums[i] <= mid){
                i+=2;
                count++;
            }else{
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(canpick(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
