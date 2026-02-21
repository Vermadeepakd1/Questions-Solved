class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        set<int> st = {2,3,5,7,11,13,17,19};
        for(int i = left; i<=right; i++){
            if(st.count(__builtin_popcount(i)))cnt++;
        }
        return cnt;
    }
};