class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int i = 0;
        while(s[i]=='a')i++;
        if(i==n){
            s[i-1] = 'z';
            return s;

        }
        while(s[i]!='a' && i != n){
            s[i]--;
            i++;
        }
        return s;
    }
};