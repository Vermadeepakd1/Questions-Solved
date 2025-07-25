class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int zeros = 0, maxi = INT_MIN;
        for(int num : st){
            sum += (num > 0) ? num : 0;
            maxi = max(maxi,num);
            if(num == 0) zeros++;
        }
        if(sum == 0){
            if(!zeros){
                sum = maxi;
            }
        }
        return sum;
    }
};