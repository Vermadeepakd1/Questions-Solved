class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = nums[(n - 1) / 2];
        long long ans = 0;
        for (int i : nums)
            ans += abs(i - target);
        return (int)ans;
    }
};