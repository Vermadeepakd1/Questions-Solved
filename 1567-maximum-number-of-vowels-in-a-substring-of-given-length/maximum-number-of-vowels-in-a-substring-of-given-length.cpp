class Solution {
public:
    bool isvowel(char lower) { return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'); }
    int maxVowels(string s, int k) {
        int cnt = 0, maxcnt = 0;
        int n = s.length();
        int i;
        for ( i = 0; i < k; i++) {
            if (isvowel(s[i]))
                cnt++;
        }
        maxcnt = cnt;
        while (i < n) {
            if (isvowel(s[i]))
                cnt++;
            if (isvowel(s[i - k]))
                cnt--;
            i++;
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};