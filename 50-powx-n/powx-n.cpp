class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }

        if(n ==1 ){
            return x;
        }

        if(x == 1){
            return 1;
        }


        if(n < 0){
            if(n % 2 == 0){
            return myPow((1/x)*(1/x), -(n/2));
        }
        return myPow(1/x, -(n/2) ) * myPow(1/x, -(n/2)+1);
        }

        if(n % 2 == 0){
            return myPow(x*x, n/2);
        }
        return myPow(x, n/2 ) * myPow(x, (n/2)+1);
    }
};