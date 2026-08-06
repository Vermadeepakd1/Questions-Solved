class Solution {
    bool isdiv(int t, int i){
        int prod = 1;
        while(i!=0){
            prod *= (i%10);
            i/=10;
        }
        return ((prod%t )== 0);
    }
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i<=100;i++){
            if(isdiv(t,i))return i;
        }
        return -1;
    }
};