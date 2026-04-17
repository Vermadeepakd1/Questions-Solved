class Solution {
    int rev(int n) {
        string num = to_string(n);
        reverse(num.begin(), num.end());
        return stoi(num);
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            

            int rever = rev(nums[i]);
            if ( mp.find(rever) != mp.end()) {
                ans = min(ans, abs(i - mp[rever]));
            }
            mp[nums[i]] = i;
        }

        if (ans != INT_MAX)
            return ans;
        return -1;
    }
};