class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        char ch = '.';
        int charcnt = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (charcnt == 0) {
                ch = chars[i];
                charcnt++;
            } else {
                if (chars[i] == ch) {
                    charcnt++;
                } else {
                    chars[idx] = ch;
                    idx++;
                    if (charcnt > 1) {

                        string temp = to_string(charcnt);
                        for (char c : temp) {
                            chars[idx] = c;
                            idx++;
                        }
                    }

                    charcnt = 1;
                    ch = chars[i];
                }
            }
        }
        chars[idx] = ch;
        idx++;
        if (charcnt > 1) {

            string temp = to_string(charcnt);
            for (char c : temp) {
                chars[idx] = c;
                idx++;
            }
        }
        return idx;
    }
};