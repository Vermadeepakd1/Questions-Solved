class Solution {
public:
    bool issquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; i++) {
            if (issquare(c - i * i))
                return true;
        }
        return false;
    }
};