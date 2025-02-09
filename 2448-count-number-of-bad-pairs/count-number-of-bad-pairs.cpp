class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            count += mp[diff];
            mp[diff]++;
        }
        long long total = (1LL * (n) * (n - 1)) / 2;
        return total - count;
    }
};