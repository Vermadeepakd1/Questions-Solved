class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = s+s;
        string s1, s2;
        for(int i = 0;  i<2*n;  i++){
            if(i&1){
                s1+='0';
                s2+='1';
            }else{
                s1+='1';
                s2+='0';
            }
        }

        int op1 = 0,op2 = 0;
        for(int  i = 0; i<n; i++){
            if(s[i]!= s1[i])op1++;
            if(s[i]!=s2[i])op2++;
        }

        int mini = min(op1,op2);
        int i = 0,j=n;
        while(j<2*n){
            if(s[j]!= s1[j])op1++;
            if(s[j]!=s2[j])op2++;
            j++;

            if(s1[i] != s[i])op1--;
            if(s2[i]  != s[i])op2--;
            i++;

            mini =  min(mini,min(op1,op2));
        }
        return mini;
    }
};