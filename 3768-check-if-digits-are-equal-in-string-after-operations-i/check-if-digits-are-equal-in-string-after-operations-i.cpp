class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = s;

        while(s.length() > 2){
            string temp = "";
            for(int i = 1; i < s.length(); i++) {
                temp += ((s[i]-'0' + s[i-1] -'0')%10)+'0';

            }
            s = temp;
        }
        return s[0] == s[1];
    }
};