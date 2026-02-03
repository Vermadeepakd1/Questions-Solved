class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int  n = nums.size();

        int i = 0;
        int p = 0,q=0;

        while(i<n-1 && nums[i+1] > nums[i])i++;
        p=i;
        if(p==0)return false;
        while(i<n-1 && nums[i+1] < nums[i])i++;
        q=i;
        if(p==q || q==n-1)return false;
        while(i<n-1 && nums[i+1] > nums[i])i++;
        int end = i;
        if(end!=n-1)return false;
        return true;
    }
};