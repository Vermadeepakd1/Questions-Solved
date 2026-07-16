class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd(n);
        int maxi = -1;

        for(int i = 0; i<n; i++){
            maxi = max(maxi,nums[i]);
            prefixgcd[i] = __gcd(nums[i],maxi);
        }

        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum = 0;
        for(int i = 0; i<n/2; i++){
            sum += gcd(prefixgcd[i],prefixgcd[n-i-1]);
        }
        return sum;
    }
};