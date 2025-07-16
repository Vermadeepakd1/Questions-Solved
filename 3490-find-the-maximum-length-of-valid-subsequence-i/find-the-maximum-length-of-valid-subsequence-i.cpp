class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxi = 0;
        //all odd or even
        int odd = 0,even = 0;
        for(int &num : nums){
            if(num%2 == 0) even++;
            else odd++;
        }
        maxi = max(maxi, max(odd,even));

        int count = 1;
        bool flag = nums[0] % 2;

        for(int i =1; i<nums.size(); i++){
            if(nums[i]%2 != flag){
                flag = !flag;
                count++;
            }
        }
        maxi = max(maxi,count);

        return maxi;
    }
};