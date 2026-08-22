class Solution {
public:
    bool checkDivisibility(int n) {
        int og = n;
        int sum = 0, prod = 1;
        while(n != 0){
            int rem = n % 10;
            n/=10;
            sum += rem;
            prod *= rem;
        }
        cout << sum << " " << prod;
        if(( og % (sum+prod)) == 0)return true;
        return false;
    }
};