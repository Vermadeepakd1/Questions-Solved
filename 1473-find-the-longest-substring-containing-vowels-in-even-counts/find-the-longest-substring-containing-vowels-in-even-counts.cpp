class Solution {
    bool isvowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int x = 0;
        mp[0] = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (isvowel(ch)) {
                x ^= ch;
            }
            if (mp.count(x)) {
                ans = max(ans, i - mp[x]);
            } else {
                mp[x] = i;
            }
        }
        return ans;
    }
};