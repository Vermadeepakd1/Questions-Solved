class Solution {
    int mod = 1e9+7;
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (m <= 0) return 0;
        if (n == 1) return m % mod; 

        vector<long long> up(m, 1), down(m, 1);

        for (int i = 2; i <= n; i++) {
            long long cprefdown = 0;
            long long csufup = 0;

            
            std::vector<long long> next_up(m, 0);
            for (int j = 0; j < m; j++) {
                next_up[j] = cprefdown;
                cprefdown = (cprefdown + down[j]) % mod;
            }

            for (int j = m - 1; j >= 0; j--) {
                long long oldup = up[j]; 
                down[j] = csufup;
                csufup = (csufup + oldup) % mod;
            }

            up = move(next_up);
        }

        long long ans = 0;
        for (int j = 0; j < m; j++) {
            ans = (ans + up[j] + down[j]) % mod;
        }
        return (int)ans;
    }
};