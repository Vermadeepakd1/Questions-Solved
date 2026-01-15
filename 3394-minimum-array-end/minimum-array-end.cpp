class Solution {
public:
    long long minEnd(int n, int x) {
        long long start = x;

        for(int i=0; i<n-1; i++){
           start = (x |(start+1)) ;
        }
        return start;
    }
};