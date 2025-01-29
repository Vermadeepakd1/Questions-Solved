class Solution {
public:
    int smallestEvenMultiple(int n) {
        int result =0;
        bool flag = false;
        int i =2;
        while(!flag){
            if(i%n==0){
                result = i;
                flag = true;
            }
            i+=2;
        }
        return result;
    }
};