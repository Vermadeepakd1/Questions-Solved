class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), count = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (s[i - 1] == ' ' && s[i] != ' ')) {
                count = 0;
            }
            if (s[i] != ' ')
                count++;
        }
        return count;
    }
};