class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int it : st) {
            ans = ans ^ it;
        }
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};