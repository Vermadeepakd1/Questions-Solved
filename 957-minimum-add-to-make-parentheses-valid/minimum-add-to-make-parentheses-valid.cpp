class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int curr= 0;

        for(char  ch: s){
            if(ch == ')')curr--;
            else curr++;

            if(curr <0){
                ans += (-curr);
                curr =0;
            }
        }
        return curr + ans;
    }
};