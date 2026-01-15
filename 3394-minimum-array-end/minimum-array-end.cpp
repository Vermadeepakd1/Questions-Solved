class Solution {
public:
    long long minEnd(int n, int x) {
        long long start = x;
        long long num = n-1;
        long long mask = 1;

        while(num != 0){
            while((mask & start) != 0)mask= (mask << 1);

            if(num&1){
                start |= mask;

            }
            num = (num >> 1);
            mask = (mask << 1);
        }
        return start;
    }
};