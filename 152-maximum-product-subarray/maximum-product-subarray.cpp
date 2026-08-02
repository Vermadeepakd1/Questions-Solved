class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, post =1;
        int maxi = nums[0];

        for(int i = 0; i<n;  i++){
            pre = pre*nums[i];
            post = post*nums[n-i-1];

            maxi = max(maxi, max(pre,post));

            if(pre == 0)pre=1;
            if(post==0)post=1;
        }
        return maxi;
    }
};