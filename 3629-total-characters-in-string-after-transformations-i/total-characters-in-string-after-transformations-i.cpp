class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int count = 0;
        int mod = 1e9 + 7;
        vector<int> charcount(26, 0);
        for (char c : s) {
            charcount[c - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<int> newcount(26, 0);
            for (int j = 0; j < 26; j++) {
                if (charcount[j] > 0) {
                    if (j == 25) {
                        newcount[0] = (newcount[0] + charcount[25]) % mod;
                        newcount[1] = (newcount[1] + charcount[25]) % mod;
                        continue;
                    }
                    newcount[j+1] = (newcount[j+1] + charcount[j]) % mod;
                }
            }
            charcount = newcount;
        }
        for (int i = 0; i < 26; i++) {
            count = (count% mod +  charcount[i] % mod)% mod;
        }

        return count;
    }
};