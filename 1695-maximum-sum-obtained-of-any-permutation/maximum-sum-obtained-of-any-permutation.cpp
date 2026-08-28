class Solution {
public:
    int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> da(n, 0);
        for (auto& r : requests) {
            int s = r[0], e = r[1];
            da[s]++;
            if (e + 1 < n)
                da[e + 1]--;
        }
        for (int i = 1; i < n; i++) {
            da[i] += da[i - 1];
        }

        sort(da.rbegin(), da.rend());
        sort(nums.rbegin(), nums.rend());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1ll*da[i] * nums[i];
        }
        ans = ans%mod;

        return (int)ans;
    }
};