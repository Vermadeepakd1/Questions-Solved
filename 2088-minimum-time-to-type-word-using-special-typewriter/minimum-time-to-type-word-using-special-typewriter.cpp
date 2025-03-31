class Solution {
public:
    int minTimeToType(string word) {
        char curr = 'a';
        int sec = 0;
        for(char c : word){
            int cl = abs(c - curr);
            int ccl = 26 - cl;
            sec += min(cl,ccl) + 1;
            curr = c;
        }
        return sec;
    }
};