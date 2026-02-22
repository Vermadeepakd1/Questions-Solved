class Solution {
public:
    int binaryGap(int n) {
        if((n&n-1) == 0)return 0;
        int last = -1;
        int maxi = 0;
        for(int i = 0; i<31; i++){
            if(((n >> i)&1) == 1 ){
                if(last != -1){
                    maxi = max(maxi, i-last);
                }
                last = i;
            }
        }
        return maxi;
    }
};