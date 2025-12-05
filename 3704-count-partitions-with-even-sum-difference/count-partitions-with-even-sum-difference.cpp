class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        bool odd = (total&1);
        if(odd)return 0;
        int n = nums.size();
        return n-1;
    }
};