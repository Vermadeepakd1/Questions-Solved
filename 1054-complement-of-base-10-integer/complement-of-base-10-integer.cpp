class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int num = 0;
        int pow = 0;

        while(n!=0){
            int rem = n%2;
            if(rem)rem=0;
            else rem = 1;
            // cout << rem << endl;
            rem = (rem<<pow);
            num += rem;
            pow++;
            n/=2;
            // cout << num << endl;
        }
        return num;
    }
};