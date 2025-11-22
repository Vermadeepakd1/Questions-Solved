class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length() , m = word2.length();
        int a = 0, b = 0;
        string ans = "";
        while(a < n && b < m){
            ans += word1[a];
            ans += word2[b];
            a++;
            b++;
        }
        while(a < n){
            ans += word1[a];
            a++;
        }
        while(b < m){
            ans += word2[b];
            b++;
        }

        return ans;
    }
};