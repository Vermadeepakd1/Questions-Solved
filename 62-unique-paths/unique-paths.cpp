class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int r = min(m-1,n-1);
        double res = 1;

        for(int i = 1; i<= r; i++){
            res = res * (N-r+i)/i;
        }
        return static_cast<int>(res);
    }
};