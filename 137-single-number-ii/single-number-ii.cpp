class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int k = 0; k <= 31; k++){
            int mask = (1 << k);
            int ones = 0, zeros = 0;
            for(int &num : nums){
                ones += ((num&mask) != 0) ? 1 : 0;
            }
            if(ones % 3 != 0){
                ans |= mask;
            }
        }
        return ans;
    }
};