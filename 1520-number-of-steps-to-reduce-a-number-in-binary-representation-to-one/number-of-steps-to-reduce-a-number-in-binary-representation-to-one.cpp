class Solution {
public:
    int numSteps(string s) {

        int steps = 0;
        while (s.length() > 1) {
            int n = s.length();
            if (s[n - 1] == '0')
                s.pop_back();
            else {
                s[n - 1] = '0';
                int idx = n - 2;
                while (idx >= 0 && s[idx] == '1') {
                    s[idx] = '0';
                    idx--;
                }
                if (idx == -1) {
                    s = '1' + s;
                } else {
                    s[idx] = '1';
                }
            }
            steps++;
        }

        return steps;
    }
};