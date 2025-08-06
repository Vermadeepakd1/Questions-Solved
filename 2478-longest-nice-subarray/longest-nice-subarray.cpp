class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int bitmask = 0;
        int start = 0, end = 0, length = 0;
        while(end < n){
            if( (start == end) || ((bitmask & nums[end])==0) ){
                length = max(end - start +1, length);
                bitmask |= nums[end];
                end++;
            }else {
                bitmask ^= nums[start];
                start++;
            }
        }
        return length;
    }
};