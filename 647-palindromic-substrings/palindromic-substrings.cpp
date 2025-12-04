class Solution {
    bool check(string& s, int i, int j) {
        if (i > j)
            return true;
        if (s[i] == s[j])
            return check(s, i + 1, j - 1);
        return false;
    }

public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i ; j < n; j++) {
                if (check(s, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};