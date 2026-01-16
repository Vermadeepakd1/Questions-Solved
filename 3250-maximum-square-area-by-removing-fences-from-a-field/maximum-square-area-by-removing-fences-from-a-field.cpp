class Solution {
    int mod = 1e9 + 7;

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        hFences.push_back(m);
        vFences.push_back(n);
        hFences.push_back(1);
        vFences.push_back(1);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                mp[hFences[j] - hFences[i]]++;
            }
        }

        long long ans = -1;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = 0; j < vFences.size(); j++) {

                int diff = vFences[j] - vFences[i];
                if (mp.count(diff)) {
                    ans = max(ans, 1ll*diff);
                }
            }
        }
        if(ans == -1)return -1;
        return (ans*ans)%mod;
    }
};