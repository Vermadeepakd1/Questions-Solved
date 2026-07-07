class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long digsum = 0;

        string s = to_string(n);
        for(char &ch : s){
            int num = ch - '0';
            if(num!=0){
                digsum += num;
                sum = sum*10 + num;
            }
        }
        return sum * digsum;
    }
};