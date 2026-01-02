class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)return 0;

        vector<long long> f(31,0);
        f[0] = 1;
        for(int i = 1; i<31; i++){
            f[i] = 2 * f[i-1] + 1;
        }
        int result = 0;
        bool sign  = true;

        for(int i = 30; i>=0; i--){
            int ibit = ((1<<i)&n);
            if(ibit > 0){
                if(sign)result += f[i];
                else result -= f[i];

                sign = !sign;
            }
        }

        return result;
    }
};