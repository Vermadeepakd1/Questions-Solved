class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod = 1e9 + 7;
        unordered_map<int, int> mp;

        for (auto i : points) {
            mp[i[1]]++;
        }
        long long ans = 0;
        long long running = 0;
        for (auto it : mp) {
            int count = it.second;
            if(count < 2)continue;

            long long curr = (1LL * count * (count - 1)) / 2;
            curr %= mod;

            ans = (ans + (curr * running) % mod) % mod;

            running = (running + curr) % mod;
        }

        return (int)ans;
    }
};