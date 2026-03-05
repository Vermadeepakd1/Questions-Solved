class Solution {
public:
    int minOperations(string s) {
        int op1 = 0, op2 = 0;

        for(int i = 0; i<s.length(); i++){
            if(s[i]-'0' == (i&1)){
                op2++;
            }else{
                op1++;
            }
        }
        return min(op1,op2);
    }
};