class Solution {
public:
    string clearDigits(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                s.erase(s.begin() + i);
                if (i - 1 >= 0) {
                    s.erase(s.begin() + i - 1);
                }
                i = i - 2;
            }
        }
        return s;
    }
};