class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0,cnt = 0;
        for(int i : nums){
            if(i == 1){
                cnt++;
            }else cnt = 0;
            maxi = max(cnt,maxi);
        }
        return maxi;
    }
};