class Solution {
    set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int i = 0, j=nums.size()-1;
        while(primes.count(nums[i]) == 0)i++;
        while(primes.count(nums[j]) == 0)j--;

        return j-i;
    }
};