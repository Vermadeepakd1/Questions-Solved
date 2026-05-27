class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> big(26, 0), small(26, 0);
        vector<bool> valid(26, 0);
        int n = word.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower(c)) {
                if (big[c - 'a'] == 0) {
                    small[c - 'a']++;
                } else {
                    if (small[c - 'a'] != 0) {
                        valid[c - 'a'] = false;
                    }
                    small[c - 'a']++;
                }

            } else {
                if (small[c - 'A'] != 0 && big[c - 'A'] == 0)
                    valid[c - 'A'] = true;
                big[c - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (valid[i])
                cnt++;
        }
        return cnt;
    }
};