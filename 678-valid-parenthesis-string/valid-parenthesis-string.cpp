class Solution {
public:
    bool checkValidString(string s) {
        int curr = 0;
        int extra = 0;

        for(char &ch: s){
            if(ch == '(') curr++;
            else if(ch == ')'){
                curr--;
                if(curr < 0){
                    if(extra) {
                        extra--;
                        curr = 0; 
                    }
                    else return false;
                }
            } else {
                extra++;
            }
        }

        int curr2 = 0;
        int extra2 = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ')') curr2++; 
            else if(s[i] == '('){
                curr2--; 
                if(curr2 < 0){
                    if(extra2) {
                        extra2--;
                        curr2 = 0; 
                    }
                    else return false;
                }
            } else {
                extra2++;
            }
        }
        

        if((extra >= curr) && (extra2 >= curr2)) return true;
        return false;
    }
};
