class Solution {
public:
    bool checkOnesSegment(string s) {
        int ones =0;
        int n = s.length();
        for(int i = 0; i<n; i++){
            if((i==0 && s[i] == '1' ) || (s[i-1]=='0' && s[i] =='1'))ones++;
        }
        return ones <=1;
    }
};