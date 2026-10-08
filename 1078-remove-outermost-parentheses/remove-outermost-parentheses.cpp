class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp = "";
        string ans = "";
        int curr = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (curr == 0)
                    curr++;
                else {
                    temp += ch;
                    curr++;
                }
            } else {
                if (curr == 1) {
                    curr = 0;
                    ans += temp;
                    temp = "";
                } else {
                    temp += ch;
                    curr--;
                }
            }
        }
        return ans;
    }
};