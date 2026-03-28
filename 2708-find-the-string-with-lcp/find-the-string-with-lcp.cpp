class Solution {
    vector<vector<int>> checklcp(string &word) {
        int n = word.length();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
        lcp.resize(n);
        for(int i = 0; i < n; i++) lcp[i].resize(n);
        return lcp;
    }

public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] != '\0') continue; 
            if (cur > 'z') return "";

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = cur;
                }
            }
            cur++;
        }

        if (checklcp(word) == lcp) {
            return word;
        }
        return "";
    }
};