class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> neg, pos;
        int n = nums.size();
        int ans = nums[n-1]*nums[n-2]*nums[n-3];
        for (int i : nums) {
            if (i < 0)
                neg.push_back(i);
            else
                pos.push_back(i);
        }


        int m = pos.size();
        int l = neg.size();
        if (l >= 2 && m >= 1) {
            ans = neg[0] * neg[1] * pos[m - 1];
        }
        if (l >= 1 && m >= 2) {
            ans = max(ans, pos[m - 1] * pos[m - 2] * neg[l - 1]);
        }
        if (m >= 3) {
            ans = max(ans, pos[m - 1] * pos[m - 2] * pos[m - 3]);
        }
        return ans;
    }
};