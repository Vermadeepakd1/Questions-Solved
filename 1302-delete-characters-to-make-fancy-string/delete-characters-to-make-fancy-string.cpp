class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if (n <= 2) {
            return s;
        }
        string ns = "";
        ns = ns + s[0] + s[1];
        for (int i = 2; i < n; i++) {
            if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
                continue;
            } else {
                ns.push_back(s[i]);
            }
        }
        return ns;
    }
};