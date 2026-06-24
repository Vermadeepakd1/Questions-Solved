class Solution {
public:
    int mod = 1e9+7;

    vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b){
        int m = a.size();
        vector<vector<long long>> c(m, vector<long long>(m, 0)); 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                long long sum = 0;
                for(int k = 0; k < m; k++){
                    sum = (sum + a[i][k] * b[k][j]) % mod;
                }
                c[i][j] = sum;
            }
        }
        return c;
    }

    vector<vector<long long>> matpow(vector<vector<long long>> base, long long e, long long m){
        vector<vector<long long>> res(m, vector<long long>(m, 0)); 
        for(int i = 0; i < m; i++){
            res[i][i] = 1;
        }
        while(e > 0){
            if(e % 2 == 1){
                res = mul(res, base);
            }
            base = mul(base, base);
            e = e >> 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1; 

        int m = r - l + 1;
        vector<vector<long long>> t(m, vector<long long>(m, 0)); 

        for(int j = 0; j < m; j++){
            for(int i = m - j; i < m; i++){
                t[i][j] = 1;
            }
        }

        // t^(n-1)
        vector<vector<long long>> powt = matpow(t, n - 1, m);

        long long total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                total = (total + powt[i][j]) % mod;
            }
        }

        return (int)((total * 2) % mod);
    }
};