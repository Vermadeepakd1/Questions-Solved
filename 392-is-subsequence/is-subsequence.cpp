class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int m = s.length();
        int n = t.length();
        for(int i = 0; i<n; i++){
            if(t[i] == s[j]){
                j++;
            }
            if(j == m)break;
        }
        return j==m;
    }
};