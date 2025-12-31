class Solution {
public:
    int mod = 1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        long long axorx = 0, bxorx = 0;

        for(long long i = 49; i >= n; i--){
            if(a & (1ll << i)) axorx |= (1ll << i);
            if(b & (1ll << i)) bxorx |= (1ll << i);
        }

        for(long long i = n - 1; i >= 0; i--){
            bool ai = (a & (1ll << i)) > 0;
            bool bi = (b & (1ll << i)) > 0;

            if(ai == bi){
                axorx |= (1ll << i);
                bxorx |= (1ll << i);
            } else {
                if(axorx > bxorx){
                    bxorx |= (1ll << i);
                } else {
                    axorx |= (1ll << i);
                }
            }
        }
        
        return (int)(((axorx % mod) * (bxorx % mod)) % mod);
    }
};