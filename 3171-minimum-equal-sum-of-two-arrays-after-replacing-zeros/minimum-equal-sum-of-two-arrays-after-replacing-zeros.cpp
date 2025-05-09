class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, size1 = nums1.size(), size2 = nums2.size(), zero1 = 0, zero2 = 0;
        for(int num : nums1){
            sum1 += num;
            if(num == 0){
                zero1++;
            }
        }
        for(int num : nums2){
            sum2 += num;
            if(num == 0){
                zero2++;
            }
        }
        if ( (zero1 == 0 && sum1 < sum2 + zero2) || (zero2 == 0 && sum2 < sum1 + zero1) ){
            return -1;
        }
        return max(sum1+zero1 , sum2 + zero2);
    }
};