class Solution {
public:
    int mod = 1e9+7;
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> predigsum(n + 1, 0);
        vector<long long> numupto(n, 0);
        vector<int> nonzeroupto(n, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }

        for (int i = 1; i <= n; i++) {
            predigsum[i] = predigsum[i - 1] + (s[i - 1] - '0');

            if (s[i - 1] != '0') {
                numupto[i - 1] = (((i - 2 >= 0) ? numupto[i - 2] : 0) * 10 + (s[i - 1] - '0')) % mod;
                nonzeroupto[i - 1] = ((i - 2 >= 0) ? nonzeroupto[i - 2] : 0) + 1;
            } else {
                numupto[i - 1] = (i - 2 >= 0) ? numupto[i - 2] : 0;
                nonzeroupto[i - 1] = (i - 2 >= 0) ? nonzeroupto[i - 2] : 0;
            }
        }

        vector<int> result;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            long long sum = predigsum[r + 1] - predigsum[l];

            int pten = nonzeroupto[r] - ((l - 1 >= 0) ? nonzeroupto[l - 1] : 0);
            
            long long base = (l - 1 >= 0) ? numupto[l - 1] : 0;
            long long x = (numupto[r] - (base * pow10[pten]) % mod + mod) % mod;

            long long ans = (x * sum) % mod;
            result.push_back(ans);
        }
        
        return result;
    }
};