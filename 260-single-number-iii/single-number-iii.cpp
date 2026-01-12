class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int cumxor = 0;

        for(int &i:nums)cumxor ^= i;

        int bit =0;
        while((cumxor & 1) != 1){
            bit++;
            cumxor = (cumxor >> 1);
        }

        int firstnum = 0, secondnum = 0;

        for(int &i : nums){
            if((i & (1<<bit)) != 0){
                firstnum ^= i;
            }else secondnum ^= i;
        }

        return {firstnum,secondnum};
    }
};