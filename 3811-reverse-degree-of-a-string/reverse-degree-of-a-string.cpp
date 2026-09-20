class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            int deg = 26 - (ch - 'a');
            ans += (i+1)*deg;
        }
        return ans;
    }
};