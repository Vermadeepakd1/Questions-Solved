class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int totalLen = n + m - 1;
        string ans(totalLen, '?');
        vector<bool> fixed(totalLen, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j]) return "";
                    ans[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }

        for (int i = 0; i < totalLen; i++) {
            if (ans[i] == '?') ans[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for(int j = 0; j < m; j++) {
                    if (ans[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool repaired = false;
                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            ans[i + j] = 'b';
                            repaired = true;
                            break;
                        }
                    }
                    if (!repaired) return ""; 
                }
            }
        }

        return ans;
    }
};