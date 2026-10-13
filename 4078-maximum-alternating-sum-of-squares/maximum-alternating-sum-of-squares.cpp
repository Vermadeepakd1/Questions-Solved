class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b){
            return a*a < b*b;
        });
        int n = nums.size();
        long long odds = 0, evens = 0;

        for(int i = 0; i<n/2; i++){
            odds+=nums[i]*nums[i];
        }
        for(int i = n/2; i<n; i++){
            evens+=nums[i]*nums[i];
        }

        return evens-odds;
    }
};