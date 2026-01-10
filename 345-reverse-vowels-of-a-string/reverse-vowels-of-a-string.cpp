class Solution {
    bool isvowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0, j = n - 1;

        while (i < j) {
            while (i < j && !isvowel(s[i]))
                i++;
            while (i < j && !isvowel(s[j]))
                j--;

            if (i < j) {

                swap(s[i], s[j]);

                i++, j--;
            }
        }

        return s;
    }
};