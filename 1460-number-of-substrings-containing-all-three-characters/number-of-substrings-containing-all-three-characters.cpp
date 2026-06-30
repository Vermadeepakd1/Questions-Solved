class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0 ,  c=0;
        int i = 0, j = 0;
        int result = 0;
        while(j < s.size()){
            if(s[j]=='a')a++;
            else if(s[j]=='b')b++;
            else c++;

            while (a > 0 && b > 0 && c > 0) {
                result += s.size() - j;
                if(s[i]=='a')a--;
                else if(s[i]=='b')b--;
                else c--;
                i++;
            }

            j++;
        }
        return result;
    }
};